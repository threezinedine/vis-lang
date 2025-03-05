@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Release
set cmake_cache=%base%/PCBuild/release-initial.cmake

cmake -G "MinGW Makefiles" -S %base% -B %build% -C %cmake_cache%