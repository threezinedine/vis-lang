@echo off

set current=%~dp0
set base=%~dp0../../../..
set build=%base%/build/Windows/MinGW/Debug

cd %build%
VizLang_Test.exe
cd %current%


