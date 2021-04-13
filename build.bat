@echo off
color 0F

:main
cls
g++ -o "bin/PokeBattle.exe" "src/main.cpp"
pause
goto main