workspace "Mirra"
	architecture 'x64'
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directory Relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Mirra/vendor/GLFW/include"

include "Mirra/vendor/GLFW"

project "Mirra"
	location "Mirra"
	kind "SharedLib"
	language "C++"
	
	pchheader "mpch.h"
	pchsource "Mirra/src/mpch.cpp"

	targetdir ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")

	
	files
	{
		"%{prj.name}/src/**.h",	
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	links
	{
		"GLFW",
		"opengl32.lib"
	}

	defines 
	{
		"ME_PLATFORM_WINDOWS",
		"ME_BUILD_DLL",
		"_WINDLL"		
	}
	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/".. outputdir .."/SandBox")
	}
filter "system.Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	
	filter "system:Windows"
		systemversion "latest"
	filter "configurations:Debug"
		defines "ME_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "ME_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		optimize "On"

project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir  ("bin/".. outputdir .."/%{prj.name}")
	objdir ("bin-int/".. outputdir .."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Mirra/vendor/spdlog/include",
		"Mirra/src"
	}

	links
	{
		"Mirra"	
	}

	
		defines 
		{
			"ME_PLATFORM_WINDOWS",
			"_WINDLL"		
		}
		filter "system.Windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "system:Windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		defines "HZ_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HZ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HZ_DIST"
		runtime "Release"
		optimize "on"