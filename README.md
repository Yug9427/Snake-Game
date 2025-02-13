# Snake Game in C++

## Description

This is a simple console-based Snake game implemented in C++. The game features basic snake movement, fruit collection, and score tracking. The player controls the snake using keyboard inputs to navigate the game area and avoid collisions.

## Features

- Classic snake movement (Up, Down, Left, Right)
- Fruit collection increases the score and snake length
- Collision detection (wall and self)
- Simple ASCII-based graphics
- Adjustable game speed

## Controls

- `W` - Move Up
- `S` - Move Down
- `A` - Move Left
- `D` - Move Right
- `X` - Exit Game

## Requirements

- A C++ compiler (GCC, MSVC, Clang, etc.)
- Windows OS (uses `<conio.h>` and Windows-specific functions)
- Command-line interface (CLI) to run the game

## How to Compile and Run

1. Open a terminal or command prompt.
2. Navigate to the project directory.
3. Compile the program using a C++ compiler:
   ```sh
   g++ Snake_game.cpp -o Snake_game.exe
   ```
4. Run the executable:
   ```sh
   ./Snake_game.exe
   ```

## How to Play

1. Start the game by running the compiled executable.
2. Use the control keys to navigate the snake.
3. Collect the fruit (`F`) to increase your score and snake length.
4. Avoid colliding with walls or yourself.
5. Press `X` to exit the game.

## Notes

- The game speed can be adjusted by modifying the `Sleep(100);` function inside the `GameLoop()` method.
- The game uses the `SetConsoleCursorPosition()` function to prevent screen flickering.

## Author

Developed by The Codefathers
