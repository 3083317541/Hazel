#include <hzpch.h>
#include "Application.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Events/EventDispatcher.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Hazel
{

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(new WindowsWindow());
        m_Window->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {

        while (m_Running)
        {
            m_Window->OnUpdate();
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