#include "../include/chess.h"

int is_valid_move(int row_1, int col_1, int row_2, int col_2)
{
    if (row_1 < 0 || row_1 >= BOARD_SIZE || col_1 < 0 || col_1 >= BOARD_SIZE)
        return (FAILURE);
    else if (row_2 < 0 || row_2 >= BOARD_SIZE || col_2 < 0 || col_2 >= BOARD_SIZE)
        return (FAILURE);
    else if (row_1 == row_2 && col_1 == col_2)
        return (FAILURE);
    return (SUCCESS);
}