#include "../include/chess.h"

int     is_valid_queen_move(int row_1, int col_1, int row_2, int col_2) 
{
    if (is_valid_rook_move(row_1, col_1, row_2, col_2)) 
    {
        return !is_clear_path_horizontally(row_1, col_1, col_2) || !is_clear_path_vertically(col_1, row_1, row_2);
    }
    if (!is_valid_bishop_move(row_1, col_1, row_2, col_2)) {
        return 1;
    }
    return 0;
}

int     is_valid_queen_capture(char piece, char target) 
{
    if (piece == 'q') 
        return (target >= 'A' && target <= 'Z') || target == ' ';
    if (piece == 'Q') 
        return (target >= 'a' && target <= 'z') || target == ' ';
    return 0;
}

void    is_queen_move(int *row_1, int *col_1, int *row_2, int *col_2) 
{
    char piece = board[*row_1][*col_1];
    char target = board[*row_2][*col_2];

    if (!is_valid_queen_capture(piece, target)) {
        printf("\033[31mInvalid capture\033[0m\n");
        return;
    }
    if (is_valid_queen_move(*row_1, *col_1, *row_2, *col_2)) {
        printf("\033[31mInvalid move\033[0m\n");
        return;
    }
    capturing(row_1, col_1, row_2, col_2);
}
