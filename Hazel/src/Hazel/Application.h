#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Hazel/Window.h"

namespace Hazel
{

    class HAZEL_API Application
    {

    public:

        Application();
        virtual ~Application();

        void Run();
        void OnEvent(Event& e);

    private:

        bool m_Running = true;
        std::unique_ptr<Window> m_Window;

    };

    Application* CreateApplication();

}