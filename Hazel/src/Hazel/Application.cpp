#include "Application.h"
#include "Events/EventDispatcher.h"
#include "Events/ApplicationEvent.h"

#include <iostream>

namespace Hazel
{

	Application::Application()
	{
	}

	Application::~Application()
	{
	};

	void Application::Run()
	{
		{
			WindowResizeEvent event(1280, 720);
			
			std::cout << "Event: "
				<< event.GetName()
				<< std::endl;

			std::cout << "Size: "
				<< event.GetWidth()
				<< " x "
				<< event.GetHeight()
				<< std::endl;

			OnEvent(event);
		}

		{
			WindowCloseEvent event;
			
			std::cout << "Event: "
				<< event.GetName()
				<< std::endl;

			OnEvent(event);
		}



		while (m_Running)
		{
		}
	}

	// ==================================
	// =========== Dispatcher ===========
	// ==================================

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		// ----- WindowClose -----
		dispatcher.Dispatch<WindowCloseEvent>(
			[this](WindowCloseEvent& event)
			{
				std::cout << "WindowCloseEvent handled!"
				<< std::endl;
				m_Running = false;
				return true;
			}
		);

		// ----- WindowResize -----
		dispatcher.Dispatch<WindowResizeEvent>(
			[this](WindowResizeEvent& event)
			{
				std::cout << "WindowResizeEvent handled!"
					<< std::endl;

				std::cout << "New Size: "
					<< event.GetWidth()
					<< " x "
					<< event.GetHeight()
					<< std::endl;

				return true;
			}
		);
	}

	


}
