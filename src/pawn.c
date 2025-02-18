#include "../include/chess.h"

void    is_pawn_move(int *row_1, int *col_1, int *row_2, int *col_2)
{
    if (board[*row_1][*col_1] == 'p')
    {
        if (*row_1 - 1 == *row_2 && *col_1 - 1 == *col_2)
            swap(row_1, col_1, row_2, col_2);
        else if (*row_1 - 1 == *row_2 && *col_1 + 1 == *col_2)
            swap(row_1, col_1, row_2, col_2);
        else if (*row_1 == 6 && *row_2 == 4 && *col_1 == *col_2 && board[*row_2][*col_2] == ' ')
            swap(row_1, col_1, row_2, col_2);
        else if (*row_1 - 1 == *row_2 && *col_1 == *col_2 && board[*row_2][*col_2] == ' ')
            swap(row_1, col_1, row_2, col_2);
        else
            printf(RED"Invalid move\n"RESET);
    }
    else if (board[*row_1][*col_1] == 'P')
    {
        if (*row_1 + 1 == *row_2 && *col_1 - 1 == *col_2)
            swap(row_1, col_1, row_2, col_2);
        else if (*row_1 + 1 == *row_2 && *col_1 + 1 == *col_2)
            swap(row_1, col_1, row_2, col_2);
        else
        if (*row_1 == 1 && *row_2 == 3 && *col_1 == *col_2 && board[*row_2][*col_2] == ' ')
            swap(row_1, col_1, row_2, col_2);
        else if (*row_1 + 1 == *row_2 && *col_1 == *col_2 && board[*row_2][*col_2] == ' ')
            swap(row_1, col_1, row_2, col_2);
        else
            printf(RED"Invalid move\n"RESET);
    }
}

