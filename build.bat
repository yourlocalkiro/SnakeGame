@echo off
g++ main.cpp Snake.cpp Food.cpp -o SnakeGame.exe -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lraylib -lopengl32 -lgdi32 -lwinmm -static-libgcc -static-libstdc++ -mwindows
if %errorlevel% equ 0 (
    echo Build successful!
    SnakeGame.exe
)
pause