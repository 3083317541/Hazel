#include "hzpch.h"
#include "WindowsWindow.h"

namespace Hazel
{

	WindowsWindow::WindowsWindow()
	{

		glfwInit();

		m_Window = glfwCreateWindow(
			1280,
			720,
			"Hazel Engine",
			nullptr,
			nullptr
		);

		m_Date.Width = 1280;
		m_Date.Height = 720;
	
	}


	WindowsWindow::~WindowsWindow()
	{

		glfwDestroyWindow(m_Window);

		glfwTerminate();
	
	}


	void WindowsWindow::OnUpdate()
	{

		glfwPollEvents();

		glfwSwapBuffers(m_Window);
	
	}


	unsigned int WindowsWindow::GetWidth() const { return m_Date.Width; }
	unsigned int WindowsWindow::GetHeight() const { return m_Date.Height; }


}