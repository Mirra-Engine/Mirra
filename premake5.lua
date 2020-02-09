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
IncludeDir["Glad"] = "Mirra/vendor/Glad/include"
IncludeDir["ImGui"] = "Mirra/vendor/imgui"

include "Mirra/vendor/GLFW"
include "Mirra/vendor/Glad"
include "Mirra/vendor/imgui"

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
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	defines 
	{
		"ME_PLATFORM_WINDOWS",
		"ME_BUILD_DLL",
		"_WINDLL",
		"GLFW_INCLUDE_NONE"
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
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		defines "ME_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ME_DIST"
		buildoptions "/MDd"
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
		defines "ME_DEBUG"
		buildoptions "/MDd"
		symbols "On"
	filter "configurations:Release"
		defines "ME_RELEASE"
		buildoptions "/MD"
		optimize "On"
	filter "configurations:Dist"
		defines "ME_DIST"
		buildoptions "/MDd"
		optimize "On"