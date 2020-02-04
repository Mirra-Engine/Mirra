#include "Logger.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Mirra {
	
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	void Logger::Init() {

		spdlog::set_pattern("%^ ***   %x [%T] %n: %v.%$");
		
		s_CoreLogger = spdlog::stdout_color_mt("MIRRA");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
