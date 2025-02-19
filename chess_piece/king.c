#include "../include/chess.h"

int     is_in_check(int king_row, int king_col) 
{
    for (int i = 0; i < BOARD_SIZE; i++) 
    {
        for (int j = 0; j < BOARD_SIZE; j++) 
        {
            if (board[i][j] != ' ' && board[i][j] != 'k' && board[i][j] != 'K') 
            {
                if (is_valid_move(i, j, king_row, king_col))
                {
                    return SUCCESS;
                }
            }
        }
    }
    return FAILURE;
}

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

int     is_checkmate(int king_row, int king_col) 
{
    if (!is_in_check(king_row, king_col))
        return SUCCESS;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) 
        {
            if (i == 0 && j == 0)
                continue;
            int new_row = king_row + i;
            int new_col = king_col + j;
            if (new_row >= 0 && new_row < BOARD_SIZE && new_col >= 0 && new_col < BOARD_SIZE) 
            {
                if (!is_in_check(new_row, new_col))
                    return SUCCESS;
            }
        }
    }
    return FAILURE;
}

void    is_king_move(int *row_1, int *col_1, int *row_2, int *col_2) 
{
    int row_diff = abs(*row_2 - *row_1);
    int col_diff = abs(*col_2 - *col_1);

    if (can_castle(row_1, col_1, row_2, col_2) == SUCCESS) 
    {
        perform_castling(row_1, col_1, row_2, col_2);
    } 
    else if ((row_diff <= 1 && col_diff <= 1) && !(row_diff == 0 && col_diff == 0)) 
        capturing(row_1, col_1, row_2, col_2);
    else
        print_invalid_move();
}
