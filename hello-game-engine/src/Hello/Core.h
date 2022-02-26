#pragma once

#ifdef HO_PLATFORM_WINDOWS

	#ifdef HO_BUILD_DLL
		#define HELLO_API __declspec(dllexport)
	#else
		#define HELLO_API __declspec(dllimport)
	#endif
#else
	#error Hello game engine only supports Windows!
#endif

#define BIT(x) (1 << x)