#pragma once

#ifdef ME_PLATFORM_WINDOWS
#ifdef ME_BUILD_DLL
#define MIRRA_API __declspec(dllexport)
#else
#define MIRRA_API __declspec(dllimport)
#endif // DEBUG
#else
#error Mirra Only Supports Windows
#endif // ME_PLATFORM_WINDOWS

#ifdef ME_ENABLE_ASSERTS
#define ME_ASSERT(x, ...){if(!(x)) {LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#define ME_CORE_ASSERT(x, ...){if(!(x)) {LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
#define ME_ASSERT(x, ...)
#define ME_CORE_ASSERT(x, ...)
#endif // ME_ENABLE_ASSERTS


#define BIT(x)(1 << x)