@echo off
set/p a=
cd "%a%"
set/p b=
g++ "%b%" -o test.exe
if exist "test.exe" echo success
if not exist "test.exe" echo error
pause