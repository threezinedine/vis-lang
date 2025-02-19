echo off 

set current=%~dp0
set base=%~dp0../../..
set build=%base%/build/Windows/VC17

cmake -G "Visual Studio 17 2022" -S %base% -B %build% -DUSE_OPENGL=ON