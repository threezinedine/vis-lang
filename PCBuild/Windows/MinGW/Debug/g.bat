@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Debug
set cmake_cache=%base%/PCBuild/debug-initial.cmake

cmake -G "MinGW Makefiles" -S %base% -B %build%  -C %cmake_cache%