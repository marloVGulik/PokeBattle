@echo off
color 0F

:main
cls
g++ src/main.cpp -o bin/PB.exe
echo Done!
pause
goto main