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

#ifdef HO_ENABLED_ASSERTS
	#define HO_CORE_ASSERT(x, ...) { if (!(x)) {HO_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define HO_ASSERT(x, ...) { if (!(x)) {HO_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define HO_CORE_ASSERT(x, ...)
	#define HO_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define HO_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)