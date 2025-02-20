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
