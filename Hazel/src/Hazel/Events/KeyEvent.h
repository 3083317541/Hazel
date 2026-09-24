#pragma once

#include "Hazel/Events/Event.h"



namespace Hazel
{
	// ====================================
	// ========== Abstract_Layer ==========
	// ====================================

	// ----- KeyEvent -----
	class HAZEL_API KeyEvent : public Event	//不知道具体EventType，继续保持 抽象
	{
	public:

		inline int GetKeyCode() const
		{
			return m_KeyCode;
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode)
		{
		}

		int m_KeyCode;
	};

	// ===================================
	//========== Concrete_Layer ==========
	// ===================================


	// ----- KeyPressed ------
	class HAZEL_API KeyPressedEvent : public KeyEvent
	{
	public:

		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount)
		{
		}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int m_RepeatCount;
	};


	// ----- keyReleased -------
	class HAZEL_API KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{
		};
	
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);

	};








}