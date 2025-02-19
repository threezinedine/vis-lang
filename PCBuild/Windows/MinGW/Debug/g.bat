@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Debug

cmake -G "MinGW Makefiles" -S %base% -B %build% -DCMAKE_BUILD_TYPE=Debug -DUSE_OPENGL=ON