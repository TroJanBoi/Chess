#include "../include/chess.h"

char    find_king(void)
{
    int found_white_kine = 0;
    int found_black_king = 0;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0;j < BOARD_SIZE; j++)
        {
            if (board[i][j] == 'k')
                found_black_king = 1;
            else if (board[i][j] == 'K')
                found_white_kine = 1;
        }
    }
    if (!found_black_king)
        return ('k');
    else if (!found_white_kine)
        return ('K');
    return (0);
}