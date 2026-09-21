#include "Application.h"
#include "Events/EventDispatcher.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

#include <iostream>

namespace Hazel
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);

        if (e.IsInCategory(EventCategoryApplication))
        {
            HZ_TRACE(e.ToString());
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