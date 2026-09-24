#pragma once

#include <String>
#include <sstream>

#include "Hazel/Core.h"

namespace Hazel
{
	enum class EventType
	{
		None = 0,

		// Window
		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		//App
		AppTick,
		AppUpdate,
		AppRender,

		// Key
		KeyPressed,
		KeyReleased,

		// Mouse
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};


	enum EventCategory
	{
		None = 0,

		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)

	};


	// 类 和 对象 都可以获得事件 类型 和 类别
	#define EVENT_CLASS_TYPE(type) \
			static EventType GetStaticType() { return EventType::type; } \
			virtual EventType GetEventType() const override { return GetStaticType(); } \
			virtual const char* GetName() const override { return #type; }
	#define EVENT_CLASS_CATEGORY(category) \
			virtual int GetCategoryFlags() const override { return category; }


	class HAZEL_API Event
	{

		friend class EventDispatcher;

	public:

		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;

	};

}