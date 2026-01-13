workspace "hello"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

	startproject "sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["root"] = "engine/src"
IncludeDir["spdlog"] = "engine/vendor/spdlog/include"
IncludeDir["glfw"] = "engine/vendor/glfw/include"
IncludeDir["glad"] = "engine/vendor/glad/include"
IncludeDir["imgui"] = "engine/vendor/imgui"
IncludeDir["glm"] = "engine/vendor/glm"

group "Dependenices"
	include "engine/vendor/glfw"
	include "engine/vendor/glad"
	include "engine/vendor/imgui"

group ""

project "engine"
	location "engine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hopch.h"
	pchsource "engine/src/hopch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{IncludeDir.root}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glfw}",
		"%{IncludeDir.glad}",
		"%{IncludeDir.imgui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"HO_PLATFORM_WINDOWS",
			"HO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		links {
			"opengl32.lib"
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/sandbox/\"")
		}

	filter "system:macosx"
		cppdialect "C++17"

		defines {
			"HO_PLATFORM_MAC",
			"HO_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		links {
			"OpenGL.framework",
			"Cocoa.framework",
			"IOKit.framework",
			"CoreVideo.framework"
		}

	filter "configurations:Debug"
		defines "HO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HO_DIST"
		runtime "Release"
		optimize "On"

project "sandbox"
	location "sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{IncludeDir.root}",
		"%{IncludeDir.spdlog}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.imgui}"
	}

	links {
		"engine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines {
			"HO_PLATFORM_WINDOWS"
		}

	filter "system:macosx"
		cppdialect "C++17"

		defines {
			"HO_PLATFORM_MAC"
		}

	filter "configurations:Debug"
		defines "HO_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "HO_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "HO_DIST"
		runtime "Release"
		optimize "On"