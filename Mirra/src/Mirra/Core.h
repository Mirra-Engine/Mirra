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
