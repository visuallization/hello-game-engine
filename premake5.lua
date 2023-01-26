workspace "hello-game-engine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["root"] = "hello-game-engine/src"
IncludeDir["spdlog"] = "hello-game-engine/vendor/spdlog/include"
IncludeDir["glfw"] = "hello-game-engine/vendor/glfw/include"
IncludeDir["glad"] = "hello-game-engine/vendor/glad/include"

include "hello-game-engine/vendor/glfw"
include "hello-game-engine/vendor/glad"

project "hello-game-engine"
	location "hello-game-engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hopch.h"
	pchsource "hello-game-engine/src/hopch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{IncludeDir.root}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}"
	}

	links {
		"GLFW",
		"Glad",	
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"HO_PLATFORM_WINDOWS",
			"HO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "HO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HO_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HO_DIST"
		buildoptions "/MD"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"hello-game-engine/vendor/spdlog/include",
		"hello-game-engine/src"
	}

	links {
		"hello-game-engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"HO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "HO_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "HO_DIST"
		buildoptions "/MD"
		optimize "On"