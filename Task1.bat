@echo off
set/p a=
cd "%a%"
set/p b=
g++ "%b%" -o functest.exe
functest.exe
pause