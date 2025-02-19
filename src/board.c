#include "../include/chess.h"

// char board[BOARD_SIZE][BOARD_SIZE] = {
//     {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
//     {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//     {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
//     {'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'}
// };

char    board[BOARD_SIZE][BOARD_SIZE] = {
    {'R', ' ', ' ', ' ', 'K', ' ', ' ', 'R'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', 'P', 'p', ' ', ' ', ' ', ' '},
    {'r', 'n', ' ', ' ', 'k', ' ', ' ', 'r'},
};

void print_board(void) {
    printf(MAGENTA"  a b c d e f g h\n"RESET);
    printf(" -----------------\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(YELLOW"%d%s|", i + 1, RESET);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf(YELLOW"%d\n"RESET, i + 1);
    }
    printf(" -----------------\n");
    printf(MAGENTA"  a b c d e f g h\n"RESET);
}
