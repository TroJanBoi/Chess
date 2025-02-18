#include "../include/chess.h"

int is_valid_pawn_move(int row_1, int col_1, int row_2, int col_2, char piece, char target)
{
    int row_diff = row_2 - row_1;
    int col_diff = abs(col_2 - col_1);

    if (piece == 'p') 
    {
        if ((row_diff == -1 && col_diff == 0 && target == ' ') ||
            (row_diff == -1 && col_diff == 1 && target >= 'A' && target <= 'Z') ||
            (row_1 == 6 && row_2 == 4 && col_1 == col_2 && target == ' '))
            return 1;
    }
    else if (piece == 'P') 
    {
        if ((row_diff == 1 && col_diff == 0 && target == ' ') ||
            (row_diff == 1 && col_diff == 1 && target >= 'a' && target <= 'z') ||
            (row_1 == 1 && row_2 == 3 && col_1 == col_2 && target == ' '))
            return 1;
    }
    return 0;
}

void is_pawn_move(int *row_1, int *col_1, int *row_2, int *col_2)
{
    char piece = board[*row_1][*col_1];
    char target = board[*row_2][*col_2];

    if (is_valid_pawn_move(*row_1, *col_1, *row_2, *col_2, piece, target))
        swap(row_1, col_1, row_2, col_2);
    else
        printf(RED"Invalid move\n"RESET);
}