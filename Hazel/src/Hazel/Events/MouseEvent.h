#pragma once

#include "Hazel/Events/Event.h"



namespace Hazel
{
	// ====================================
	// ========== Abstract_Layer ==========
	// ====================================

	class MouseButtonEvent : public Event
	{
	public:

		int GetMouseButton() const
		{
			return m_Button;
		}

	protected:

		MouseButtonEvent(int button)
			: m_Button(button)
		{

		}

		int m_Button;

	};

	// ====================================
	// ========== Concrete_Layer ==========
	// ====================================

	// ----- MouseMoved -----
	class MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y)
		{
		}

		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		EVENT_CLASS_TYPE(MouseMoved)
		const char* GetName() const override { return "MouseMoved"; }
		int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }

	private:

		float m_MouseX;
		float m_MouseY;

	};

	// ----- MouseButtonPressed -----
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{
		}


		EVENT_CLASS_TYPE(MouseButtonPressed)
		const char* GetName() const override { return "MouseButtonPressed"; }
		int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }


	};

	// ----- MouseButtonReleased -----
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{
		}


		EventType GetEventType() const override { return EventType::MouseButtonReleased; }
		const char* GetName() const override { return "MouseButtonReleased"; }
		int GetCategoryFlags() const override { return EventCategoryMouse | EventCategoryInput; }


	};


}