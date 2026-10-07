# 🐍 Basic Snake Game

A simple Snake game made in **C++ using Raylib**.

This project was built as a learning project to practice **C++ OOP, game loops, collision detection, input handling, audio, and basic game development**.
[Mostly out of curiosity, as I saw many people create the same project using Python, but no one worked with C or C++. So i wondered how hard it could possibly be?]

---

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

---

## 🕹️ Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move Up |
| `A` / `←` | Move Left |
| `S` / `↓` | Move Down |
| `D` / `→` | Move Right |
| `ENTER` | Start Game |
| `R` | Restart after Game Over / Win |

---

## 🛠️ Built With

- **C++**
- **Raylib 5.5**
- **MSYS2 / MinGW-w64**
- **Visual Studio Code**

---

## 📁 Project Structure

```text
SnakeGame/
├── main.cpp
├── Snake.cpp
├── Snake.h
├── Food.cpp
├── Food.h
├── embed_audio.py
├── eat.h
├── left.h
├── right.h
├── up.h
├── down.h
├── win.h
├── death.h
└── Audio/
    ├── EAT.wav
    ├── LEFT.wav
    ├── RIGHT.wav
    ├── UP.wav
    ├── DOWN.wav
    ├── WIN.wav
    └── DEATH.wav
