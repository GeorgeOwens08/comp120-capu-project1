# Tic-Tac-Toe vs. Computer

## Description

This project is a simple Tic-Tac-Toe game written in C where the user plays against the computer on a 3x3 board. The user plays as O and goes first, while the computer plays as X and randomly selects its moves.

The game continues until either the user or computer wins, or the game ends in a draw. The user can also choose to play multiple games without restarting the program.

The program demonstrates basic C programming concepts, including:

- Using 1-D character arrays to store the game board
- Using functions to organize the code
- Using loops to control the game
- Checking for wins and draws
- Random number generation for computer moves
- Input validation to prevent invalid moves

## Code Overview

The project is organized around several functions:

- `init_board()` – Sets all board positions to empty.
- `display_board()` – Displays the board and available square numbers.
- `is_winner()` – Checks if a player has three symbols in a row, column, or diagonal.
- `other_player()` – Switches between the two players.
- `get_human_move()` – Gets the user's move and checks that it is valid.
- `get_computer_move()` – Randomly selects an empty square for the computer.
- `take_turn()` – Handles a player's turn.
- `play_game()` – Controls the main game and checks for wins or draws.
- `play_again()` – Asks the user if they want to play another game.

## How to Run

1. Clone or download this repository.
2. Open the project file `tictactoe.c` in your C IDE or text editor.
3. Compile the program using GCC:

```bash
gcc tictactoe.c -o tictactoe
```

4. Run the program:

```bash
./tictactoe
```

5. Follow the instructions to play. Enter a number from 0 to 8 to choose your square, and enter `y` or `q` at the end of a game to play again or quit.

## Author
George Owens
