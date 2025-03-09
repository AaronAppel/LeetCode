@echo off

call Premake\premake5.exe --file="Premake\leetcode.lua" vs2022

IF NOT %errorlevel%==0 (
	echo Encountered error!
	pause
)