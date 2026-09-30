#pragma once

#include "hzpch.h"
#include "WindowsWindow.h"

struct GLFWwindow;

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

		glfwSetWindowUserPointer(m_Window, &m_Data);

		m_Data.Width = 1280;
		m_Data.Height = 720;
	
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


	unsigned int WindowsWindow::GetWidth() const { return m_Data.Width; }
	unsigned int WindowsWindow::GetHeight() const { return m_Data.Height; }


}