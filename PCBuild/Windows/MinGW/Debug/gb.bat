@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Debug
set bin=%base%/build/Windows/MinGW/Debug/bin
set cmake_cache=%base%/PCBuild/debug-initial.cmake

cmake --build %build% --target install