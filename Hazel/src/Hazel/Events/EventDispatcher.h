#pragma once

#include "Hazel/Events/Event.h"



namespace Hazel
{

	class EventDispatcher
	{
	public:

		EventDispatcher(Event& event)
			: m_Event(event)
		{
		}


		template<typename T, typename F>
		bool Dispatch(const F& fun)
		{

			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled |= fun(static_cast<T&>(m_Event));
				return true;
			}

			return false;
		}


	private:
		Event& m_Event;

	};







}


























