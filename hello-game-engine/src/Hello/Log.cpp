#include "hopch.h"
#include "Log.h"

namespace Hello {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		// change log pattern
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// create color multi threaded logger
		s_CoreLogger = spdlog::stdout_color_mt("HELLO");
		// level trace logs everything
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}