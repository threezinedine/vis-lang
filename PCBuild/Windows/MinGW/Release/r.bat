@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Release

cd %build%
VizLang.exe
cd %current%


