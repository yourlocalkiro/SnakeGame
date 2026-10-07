# 🐍 Basic Snake Game

A simple Snake game made in **C++ using Raylib**.

This project was built as a learning project to practice **C++ OOP, game loops, collision detection, input handling, audio, and basic game development**.

[Mostly out of curiosity, as I saw many people create the same project using Python, but no one worked with C or C++. So I wondered how hard it could possibly be?]

## 🎮 Features

- Classic Snake gameplay
- WASD and Arrow Key controls
- Snake grows when eating food
- Increasing movement speed
- Self-collision detection
- Wall collision detection
- Score system
- High score tracking
- Main menu
- Game Over screen
- Win condition
- Restart functionality
- Directional sound effects
- Eating, death, and victory sounds
- Embedded audio — the final `.exe` does not require separate audio files
- Simple checkerboard-style game background

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move Up |
| `A` / `←` | Move Left |
| `S` / `↓` | Move Down |
| `D` / `→` | Move Right |
| `ENTER` | Start Game |
| `R` | Restart after Game Over / Win |

## 🛠️ Built With

- **C++**
- **Raylib 5.5**
- **MSYS2 / MinGW-w64**
- **Visual Studio Code**

## 🔊 Embedded Audio

The game embeds its sound effects directly into the executable.

The **`embed_audio.py`** script converts the WAV files into C++ header files containing the audio data. The game then loads the sounds using Raylib's memory-based audio functions.

This means the final executable **can be distributed as a single `.exe` file** without requiring a separate `Audio` folder.


## 🧠 What I Learned

While making this project, I got hands-on experience with:

- C++ classes and objects
- Object-oriented programming
- Header (`.h`) and source (`.cpp`) files
- Constructors
- Encapsulation
- `std::vector`
- Passing data between classes
- Game loops
- Keyboard input
- Collision detection
- Game state management
- Random number generation
- Audio handling
- Working with external libraries
- Compiling and linking C++ programs
- Creating a standalone executable
- Embedding external assets into an executable

## ⚙️ Building From Source

### Requirements

- Windows
- C++ compiler with MinGW-w64
- Raylib 5.5
- Python 3.x

### Compile

If Raylib is installed through MSYS2 UCRT64:

```bash
g++ main.cpp Snake.cpp Food.cpp -o SnakeGame.exe \
    -IC:/msys64/ucrt64/include \
    -LC:/msys64/ucrt64/lib \
    -lraylib -lopengl32 -lgdi32 -lwinmm
```
