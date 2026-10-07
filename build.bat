@echo off

g++ main.cpp Snake.cpp Food.cpp -o SnakeGame.exe ^
    -I"C:/msys64/home/kichr/raylib-static/src" ^
    -L"C:/msys64/home/kichr/raylib-static/src" ^
    -Wl,-Bstatic ^
    -lraylib ^
    -Wl,--whole-archive,"C:/msys64/ucrt64/lib/libwinpthread.a",--no-whole-archive ^
    -Wl,-Bdynamic ^
    -lopengl32 -lgdi32 -lwinmm ^
    -static-libgcc -static-libstdc++ ^
    -mwindows

if %errorlevel% equ 0 (
    echo Build successful!
    SnakeGame.exe
)

pause