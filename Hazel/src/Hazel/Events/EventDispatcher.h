#pragma once

#include "Hazel/Events/Event.h"
#include <functional>

namespace Hazel
{

	class EventDispatcher
	{
	public:

		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}


		template<typename T>
		using EventFn = std::function<bool(T&)>;

		template<typename F>
		bool Dispatch(const EventFn<F> func)
		{
			if (m_Event.GetEventType() == F::GetStaticType())
			{
				m_Event.m_Handled |= func(static_cast<F&>(m_Event));
				return true;
			}

			return false;
		}

	private:
		Event& m_Event;

	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}


























