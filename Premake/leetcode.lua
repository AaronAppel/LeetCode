workspace "LeetCode"

	-- Workspace specific settings
	startproject "LeetCode"
	location "../"

	-- Solution wide shared settings
	configurations { "Debug", "Release", }
	flags { "MultiProcessorCompile" }
	rtti "Off"
	staticruntime "off" -- https://premake.github.io/docs/staticruntime
	language "C++"
	cppdialect "C++17"

	filter "configurations:*86"
		architecture "x86"
		
	filter "configurations:*64"
		architecture "x64"

	OutputDir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"
		
	filter "configurations:Debug"
		targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
		objdir ("%{wks.location}/bin/int/" .. OutputDir .. "/%{prj.name}")
		runtime "Debug"
		symbols "on"
		optimize "off"
		
	filter "configurations:Release"
		targetdir ("%{wks.location}/bin/" .. OutputDir .. "/%{prj.name}")
		objdir ("%{wks.location}/bin/int/" .. OutputDir .. "/%{prj.name}")
		runtime "Release"
		symbols "off"
		optimize "on"
	
	-- Project
	project "LeetCode"
	kind "ConsoleApp"
	location ""
	
	files
	{
		"../Source/**.h",
		"../Source/**.cpp",
	}
