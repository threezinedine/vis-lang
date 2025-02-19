@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Release

cd %build%
mingw32-make
cd %current%