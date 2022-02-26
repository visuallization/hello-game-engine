workspace "hello-game-engine"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "hello-game-engine"
	location "hello-game-engine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"HO_PLATFORM_WINDOWS",
			"HO_BUILD_DLL"
		}
		
		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/sandbox")
		}

	filter "configurations:Debug"
		defines "HO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HO_DIST"
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
		symbols "On"

	filter "configurations:Release"
		defines "HO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HO_DIST"
		optimize "On"