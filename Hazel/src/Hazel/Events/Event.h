#pragma once

#include "Hazel/Core.h"

enum class EventType
{
	None = 0,

	// Window
	WindowClose,
	WindowResize,

	// Key
	KeyPressed,
	KeyReleased,

	// Mouse
	MouseButtonPressed,
	MouseButtonReleased,
	MouseMoved
};


enum EventCategory
{
	None = 0,

	EventCategoryApplication = BIT(0),
	EventCategoryInput = BIT(1),
	EventCategoryKeyboard = BIT(2),
	EventCategoryMouse = BIT(3),

};

// 类 和 对象 都可以获得事件 类型 和 类别
#define EVENT_CLASS_TYPE(type) \
		static EventType GetStaticType() { return EventType::type; } \
		virtual EventType GetEventType() const override { return GetStaticType(); } 
#define EVENT_CLASS_CATEGORY(category) \
		virtual int GetCategoryFlags() cosnt override { return category; }

namespace Hazel
{

	class Event
	{
	public:

		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;

		bool m_Handled = false;

	};












}