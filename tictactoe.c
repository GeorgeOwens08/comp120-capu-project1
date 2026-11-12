
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void init_board(char board[]);
void display_board(char board[]);
bool is_winner(char board[], char player);
char other_player(char player);
int get_human_move(char board[]);
int get_computer_move(char board[]);
void take_turn(char board[], char player);
void play_game(void);
bool play_again(void);

int main(void) {

    printf("=====================================\n");
    printf("       TIC-TAC-TOE vs COMPUTER\n");
    printf("=====================================\n");
    printf("You are O and you go first. The computer is X.\n");
    printf("On your turn, enter the number of an empty square.\n");

    do {
        play_game();
    } while (play_again());

    printf("\nThanks for playing!\n");

    return 0;
}

void init_board(char board[]) {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void display_board(char board[]) {
    char c[9];

    for (int i = 0; i < 9; i++) {
        c[i] = board[i];

        if (c[i] == ' ') {
            c[i] = '0' + i;
        }
    }

    printf("\n %c | %c | %c\n", c[0], c[1], c[2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", c[3], c[4], c[5]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n\n", c[6], c[7], c[8]);
}

bool is_winner(char board[], char player) {

    for (int i = 0; i < 9; i += 3) {
        if (board[i] == player &&
            board[i + 1] == player &&
            board[i + 2] == player) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[i] == player &&
            board[i + 3] == player &&
            board[i + 6] == player) {
            return true;
        }
    }

    if (board[0] == player &&
        board[4] == player &&
        board[8] == player) {
        return true;
    }

    if (board[2] == player &&
        board[4] == player &&
        board[6] == player) {
        return true;
    }

    return false;
}

char other_player(char player) {
    if (player == 'O') {
        return 'X';
    }
    else {
        return 'O';
    }
}

int get_human_move(char board[]) {
    int move;
    bool valid = false;

    while (!valid) {
        printf("Your turn (O). Enter a square number (0-8): ");

        if (scanf("%d", &move) != 1) {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n');
        }
        else if (move < 0 || move > 8) {
            printf("Invalid square. Choose a number from 0 to 8.\n");
        }
        else if (board[move] != ' ') {
            printf("That square is already taken. Choose an empty one.\n");
        }
        else {
            valid = true;
        }
    }

    return move;
}

int get_computer_move(char board[]) {
    int move;

    do {
        move = rand() % 9;
    } while (board[move] != ' ');

    return move;
}

void take_turn(char board[], char player) {
    int move;

    if (player == 'O') {
        move = get_human_move(board);
    }
    else {
        printf("\nComputer (X) is thinking...\n");

        move = get_computer_move(board);

        printf("Computer (X) chose square %d. Your move next!\n", move);
    }

    board[move] = player;
}

void play_game(void) {
    char board[9];
    char player = 'O';
    bool game_over = false;

    init_board(board);
    display_board(board);

    for (int turn = 0; turn < 9 && !game_over; turn++) {

        take_turn(board, player);

        display_board(board);

        if (is_winner(board, player)) {

            if (player == 'O') {
                printf("Congratulations! You won!\n");
            }
            else {
                printf("The computer wins! Better luck next time.\n");
            }

            game_over = true;
        }

        else if (turn == 8) {
            printf("It's a draw!\n");
            game_over = true;
        }

        else {
            player = other_player(player);
        }
    }
}

bool play_again(void) {
    char answer;

    do {
        printf("\nWould you like to play again? (y/q): ");
        scanf(" %c", &answer);

        if (answer != 'y' && answer != 'q') {
            printf("Please enter y or q.\n");
        }

    } while (answer != 'y' && answer != 'q');

    return answer == 'y';
}

