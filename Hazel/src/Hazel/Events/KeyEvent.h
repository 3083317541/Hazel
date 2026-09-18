#pragma once

#include "Hazel/Events/Event.h"



namespace Hazel
{
	// ====================================
	// ========== Abstract_Layer ==========
	// ====================================

	// ----- KeyEvent -----
	class KeyEvent : public Event	//不知道具体EventType，继续保持 抽象
	{
	public:

		int GetKeyCode() const
		{
			return m_KeyCode;
		}

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
	class KeyPressedEvent : public KeyEvent
	{
	public:

		KeyPressedEvent(int keycode)
			: KeyEvent(keycode)
		{
		}

		EVENT_CLASS_TYPE(KeyPressed)	
		const char* GetName() const override { return "KeyPressed"; }
		int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }
	};


	// ----- keyReleased -------
	class KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode)
		{
		};
	
		EventType GetEventType() const override { return EventType::KeyReleased; }
		const char* GetName() const override { return "KeyReleased"; }
		int GetCategoryFlags() const override { return EventCategoryKeyboard | EventCategoryInput; }

	};








}