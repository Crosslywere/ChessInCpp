workspace "ChessInCpp"
	architecture "x64"
	configurations { "Debug", "Release" }

	startproject "ChessInCpp"

	project "glfw"
		kind "StaticLib"
		language "C"
		cdialect "C17"
		targetdir "bin/%{cfg.buildcfg}/glfw"
		objdir "obj/%{cfg.buildcfg}/glfw"
		defines "_CRT_SECURE_NO_WARNINGS"
		files {
			"glfw/include/**.h",
			"glfw/src/context.c",
			"glfw/src/init.c",
			"glfw/src/input.c",
			"glfw/src/monitor.c",
			"glfw/src/platform.c",
			"glfw/src/vulkan.c",
			"glfw/src/window.c",
			"glfw/src/wgl_context.c",
			"glfw/src/egl_context.c",
			"glfw/src/glx_context.c",
			"glfw/src/osmesa_context.c",
			"glfw/src/null_init.c",
			"glfw/src/null_joystick.c",
			"glfw/src/null_monitor.c",
			"glfw/src/null_window.c",
		}
		vpaths {
			["Header"] = "**.h",
			["Source"] = "**.c"
		}
		filter "system:windows"
			defines "_GLFW_WIN32"
			files {
				"glfw/src/win32_init.c",
				"glfw/src/win32_joystick.c",
				"glfw/src/win32_module.c",
				"glfw/src/win32_monitor.c",
				"glfw/src/win32_thread.c",
				"glfw/src/win32_time.c",
				"glfw/src/win32_window.c"
			}
		filter "configurations:Debug"
			runtime "Debug"
			symbols "On"		
		filter "configurations:Release"
			runtime "Release"
			symbols "Off"
			optimize "On"

	project "glad"
		kind "StaticLib"
		location "glad"
		language "C"
		cdialect "C17"
		targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
		objdir "obj/%{cfg.buildcfg}/%{prj.name}"
		files {
			"%{prj.location}/**.h",
			"%{prj.location}/**.c"
		}
		includedirs {
			"%{prj.location}/include"
		}
		vpaths {
			["Header"] = "**.h",
			["Source"] = "**.c"
		}

	project "Engine"
		kind "StaticLib"
		location "Engine"
		language "C++"
		cppdialect "C++20"
		targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
		objdir "obj/%{cfg.buildcfg}/%{prj.name}"
		files {
			"%{prj.location}/src/**.h",
			"%{prj.location}/src/**.cpp",
			"%{prj.location}/include/**.h"
		}
		vpaths {
			["Header"] = "**.h",
			["Source"] = "**.c"
		}
		links {
			"glfw",
			"glad"
		}
		includedirs {
			"glfw/include",
			"glad/include",
			"glm",
			"%{prj.location}/include"
		}
		pchheader "pch.h"
		pchsource "%{prj.location}/src/pch.cpp"
		filter "configurations:Debug"
			runtime "Debug"
			defines "DEBUG"
			symbols "On"
		filter "configurations:Release"
			runtime "Release"
			symbols "Off"
			optimize "On"

	project "ChessInCpp"
		language "C++"
		cppdialect "C++20"
		location "ChessInCpp"
		targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
		objdir "obj/%{cfg.buildcfg}/%{prj.name}"
		files {
			"%{prj.location}/src/**.h",
			"%{prj.location}/src/**.cpp",
			"%{prj.location}/res/**"
		}
		vpaths {
			["Header"] = "**.h",
			["Source"] = { "**.c", "**.cpp" },
			["Resource"] = "res/**"
		}
		links {
			"Engine"
		}
		includedirs {
			"Engine/include",
			"glm"
		}
		filter "configurations:Debug"
			runtime "Debug"
			defines "DEBUG"
			kind "ConsoleApp"
			symbols "On"
		filter "configurations:Release"
			runtime "Release"
			kind "WindowedApp"
			symbols "Off"
			optimize "On"
