set base=%~dp0
set docs=%base%/docs

cd %docs%
Doxygen
html\index.html
cd %base%