#include "../include/chess.h"

int     can_castle(int *row_1, int *col_1, int *row_2, int *col_2) 
{
    if (has_moved[*row_1][*col_1] || !is_in_check(*row_1, *col_1))
        return FAILURE;

    if (*col_2 == 7) 
    {
        if (has_moved[*row_1][7] || !is_clear_path_horizontally(*row_1, *col_1, 7))
            return FAILURE;
        if (!is_in_check(*row_1, *col_1 + 1) || !is_in_check(*row_1, *col_1 + 2))
            return FAILURE;
        return SUCCESS;
    } 
    else if (*col_2 == 0)
    {
        if (has_moved[*row_1][0] || !is_clear_path_horizontally(*row_1, *col_1, 0))
            return FAILURE;
        if (!is_in_check(*row_1, *col_1 - 1) || !is_in_check(*row_1, *col_1 - 2))
            return FAILURE;
        return SUCCESS;
    }
    return FAILURE;
}

void perform_castling(int *row_1, int *col_1, int *row_2, int *col_2) 
{
    if (*col_2 == 7 || *col_2 == 0) {
        swap_castle(row_1, col_1, row_2, col_2);
    }
    has_moved[*row_1][*col_1] = 1;
    has_moved[*row_2][(*col_2 == 7 ? 5 : 3)] = 1;
}

void swap_castle(int *king_row, int *king_col, int *rook_row, int *rook_col) 
{
    int new_king_col = (*rook_col == 7) ? 6 : 2;
    int new_rook_col = (*rook_col == 7) ? 5 : 3;

    board[*king_row][new_king_col] = board[*king_row][*king_col];
    board[*king_row][*king_col] = ' ';
    board[*rook_row][new_rook_col] = board[*rook_row][*rook_col];
    board[*rook_row][*rook_col] = ' ';
    *king_col = new_king_col;
    *rook_col = new_rook_col;
}
