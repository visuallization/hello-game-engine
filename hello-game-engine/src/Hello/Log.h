#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Hello {

	class HELLO_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define HO_CORE_TRACE(...)	::Hello::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HO_CORE_INFO(...)	::Hello::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HO_CORE_WARN(...)	::Hello::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HO_CORE_ERROR(...)	::Hello::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define HO_TRACE(...)		::Hello::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HO_INFO(...)		::Hello::Log::GetClientLogger()->info(__VA_ARGS__)
#define HO_WARN(...)		::Hello::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HO_ERROR(...)		::Hello::Log::GetClientLogger()->error(__VA_ARGS__)
