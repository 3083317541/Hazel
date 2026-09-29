#pragma once

#include <GLFW/glfw3.h>
#include "Hazel/Window.h"

namespace Hazel
{

	class WindowsWindow : public Window
	{

	public:

		WindowsWindow(
			const std::string& title = "Hazel Engine",
			unsigned int width = 1280,
			unsigned int height = 720);
		
		
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth()  const override { return m_Date.Width; };
		unsigned int GetHeight() const override { return m_Date.Height; };

		void SetEventCallback(const EventCallbackFn& callback) override { m_Date.EventCallback = callback; }

	private:

		void Init(const std::string& title, unsigned int width, unsigned int height);
		void Shutdown();

		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width;
			unsigned int Height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Date;

	};

}
