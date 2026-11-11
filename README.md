# Hangman (C++)

A console version of the word game **Hangman**, written in C++20 for COMP 3450. One player enters a secret word, and the guesser tries to uncover it one letter at a time before running out of allowed mistakes. There are three difficulty modes.

## How to play

1. Enter a difficulty: `easy`, `regular` or `hard`. Any other text is treated as `hard`.
2. Enter the secret word.
3. Guess one letter at a time. After each guess the game shows the mistake count, the clue with correctly guessed letters filled in, and the wrong letters guessed so far in alphabetical order.
4. The game ends when every letter is revealed (`You won!`) or the mistake limit is reached (`You lost.`), and then shows the word.

Input isn't case-sensitive; everything is converted to uppercase.

### Difficulty modes

| Mode | Mistakes allowed | Repeating a guess |
| --- | --- | --- |
| Easy | 9 | Free |
| Regular | 9 | Counts as a mistake |
| Hard | 6 | Counts as a mistake |

### Example

```
easy cat
Hangman
-------

Mistakes: 0/9
Clue:     ___

a
Guess: A

Mistakes: 0/9
Clue:     _A_

z
Guess: Z

Mistakes: 1/9
Clue:     _A_
Wrong:    Z
...
You won!
The word was: CAT
```

## How the code is organized

The code is split into three parts: input/output, game rules and the game loop.

| File | Description |
| --- | --- |
| `Hangman/Hangman.cpp` | `main`: creates a `hangman::Game` and starts it. |
| `Hangman/game.hpp`, `game.cpp` | `Game::playGame()`, the main loop that reads guesses, updates the state and checks for a win or loss. |
| `Hangman/state.hpp`, `state.cpp` | `hangman::State`, the game rules: the difficulty `Modes` enum, mistake limits, building and updating the clue, tracking right and wrong letters, and checking for a win or loss. |
| `Hangman/console.hpp`, `console.cpp` | `IO::Input` (reads and uppercases the difficulty, word and guesses) and `IO::Output` (prints the title, mistakes, clue, wrong letters and result). |
| `CMakeLists.txt`, `CMakePresets.json`, `Hangman/CMakeLists.txt` | CMake build files and presets for Windows, Linux and macOS. |

## Building and running

Requires CMake 3.8 or later and a C++20 compiler.

**Visual Studio:** open the folder as a CMake project and run the **Hangman** target.

**Command line:**

```
cmake -S . -B build
cmake --build build
./build/Hangman/Hangman
```

Or compile directly:

```
g++ -std=c++20 -o hangman Hangman/*.cpp
```

Each run plays one round. Start the program again to play another word.

## Project notes

- **Course:** COMP 3450
- **Author:** Simon Diaz
- **Description:** A version of Hangman with easy, regular and hard modes, each with its own challenge. The goal is to guess the word within the allotted attempts.
- **What I'd improve:** Organizing the code into better-designed functions.
- **Strengths:** Making good use of functions and getting the most out of each one.
