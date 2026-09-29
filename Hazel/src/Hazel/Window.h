#pragma once

#include "Hazel/Core.h"
#include "Hazel/Events/Event.h"

#include <functional>
#include <string>

namespace Hazel
{
	
	class HAZEL_API Window
	{
	public:

		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;
		
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;


		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

	};

}
















