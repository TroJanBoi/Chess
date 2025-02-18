#include "../include/chess.h"

int is_valid_bishop_move(int row_1, int col_1, int row_2, int col_2)
{
    int row_diff = abs(row_2 - row_1);
    int col_diff = abs(col_2 - col_1);
    
    if (row_diff == col_diff) 
    {
        int row_step = (row_2 > row_1) ? 1 : -1;
        int col_step = (col_2 > col_1) ? 1 : -1;
        int r = row_1 + row_step, c = col_1 + col_step;
        
        while (r != row_2 && c != col_2) 
        {
            if (board[r][c] != ' ') 
                return 0;
            r += row_step;
            c += col_step;
        }
        return 1;
    }
    return 0;
}

int     is_valid_bishop_capture(char piece, char target)
{
    if (piece == 'b')
        return (target >= 'A' && target <= 'Z') || target == ' ';
    if (piece == 'B')
        return (target >= 'a' && target <= 'z') || target == ' ';
    return 0;
}

void    is_bishop_move(int *row_1, int *col_1, int *row_2, int *col_2)
{
    char piece = board[*row_1][*col_1];
    char target = board[*row_2][*col_2];

    if (!is_valid_bishop_capture(piece, target))
    {
        printf(RED"Invalid move\n"RESET);
        return ;
    }
    if (is_valid_bishop_move(*row_1, *col_1, *row_2, *col_2))
        capturing(row_1, col_1, row_2, col_2);
    else
        printf(RED"Invalid move\n"RESET);
}
