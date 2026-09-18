#pragma once

#include "Hazel/Events/Event.h"



namespace Hazel
{

	// ----- WindowClose ------
	class WindowCloseEvent : public Event
	{
	public:

		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		const char* GetName() const override { return "WindowClose"; }
		int GetCategoryFlags() const override { return EventCategoryApplication; }

	};


	// ----- WindowResized -----
	class WindowResizeEvent : public Event
	{
	public:

		WindowResizeEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height)	{}

		unsigned int GetWidth() const { return m_Width; }
		unsigned int GetHeight() const { return m_Height; }

		EVENT_CLASS_TYPE(WindowResize)
		const char* GetName() const override { return "WindowResizeEvent"; }
		int GetCategoryFlags() const override { return EventCategoryApplication; }

	private:
		unsigned int m_Width;
		unsigned int m_Height;

	};























}