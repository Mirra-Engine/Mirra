#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"

namespace Mirra {
	class MIRRA_API Logger {

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// CORE LOGGER MACROS
#define LOG_CORE_TRACE(...)   ::Mirra::Logger::getCoreLogger()->trace(__VA_ARGS__);
#define LOG_CORE_INFO(...)	  ::Mirra::Logger::getCoreLogger()->info(__VA_ARGS__);
#define LOG_CORE_WARN(...)	  ::Mirra::Logger::getCoreLogger()->warn(__VA_ARGS__);
#define LOG_CORE_ERROR(...)   ::Mirra::Logger::getCoreLogger()->error(__VA_ARGS__);
#define LOG_CORE_CRITICAL(...)   ::Mirra::Logger::getCoreLogger()->critical(__VA_ARGS__);

// CLIENT LOGGER MACROS
#define LOG_TRACE(...) ::Mirra::Logger::getClientLogger()->trace(__VA_ARGS__);
#define LOG_INFO(...)  ::Mirra::Logger::getClientLogger()->info(__VA_ARGS__);
#define LOG_WARN(...)  ::Mirra::Logger::getClientLogger()->warn(__VA_ARGS__);
#define LOG_ERROR(...) ::Mirra::Logger::getClientLogger()->error(__VA_ARGS__);
#define LOG_CRITICAL(...) ::Mirra::Logger::getClientLogger()->critical(__VA_ARGS__);