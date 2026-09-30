#pragma once

#include <GLFW/glfw3.h>
#include "Hazel/Window.h"

namespace Hazel
{

	class WindowsWindow : public Window
	{

	public:

		WindowsWindow();
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth()  const override;
		unsigned int GetHeight() const override;

		//回调函数 将需要用到的Event指针直接赋值给callback，让函数在这里被保存
		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }

	private:

		GLFWwindow* m_Window;	//下级GLFW指针

		struct WindowData		//数据
		{
			unsigned int Width;
			unsigned int Height;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;

	};

}
