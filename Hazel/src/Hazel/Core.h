#pragma once
#include <functional>

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif


#define BIT(x) (1 << x)


#define HZ_BIND_EVENT_FN(fn)	std::bind(&fn, this, std::placeholders::_1)







