#include "../include/chess.h"

void print_invalid_move()
{
    printf(RED"Invalid move\n"RESET);
}

int is_valid_rook_move(int row_1, int col_1, int row_2, int col_2)
{
    return (row_1 == row_2 || col_1 == col_2);
}

int is_clear_path_horizontally(int row, int col_1, int col_2)
{
    int start = col_1 < col_2 ? col_1 + 1 : col_2 + 1;
    int end = col_1 < col_2 ? col_2 : col_1;
    
    for (int i = start; i < end; i++)
    {
        if (board[row][i] != ' ')
            return 0;
    }
    return 1;
}

int is_clear_path_vertically(int col, int row_1, int row_2)
{
    int start = row_1 < row_2 ? row_1 + 1 : row_2 + 1;
    int end = row_1 < row_2 ? row_2 : row_1;
    
    for (int i = start; i < end; i++)
    {
        if (board[i][col] != ' ')
            return 0;
    }
    return 1;
}

int can_rook_capture(char piece, char target)
{
    if (piece == 'R')
        return (target >= 'a' && target <= 'z') || target == ' ';
    if (piece == 'r')
        return (target >= 'A' && target <= 'Z') || target == ' ';
    return 0;
}

void is_rook_move(int *row_1, int *col_1, int *row_2, int *col_2)
{
    char piece = board[*row_1][*col_1];
    char target = board[*row_2][*col_2];
    
    if (!is_valid_rook_move(*row_1, *col_1, *row_2, *col_2))
    {
        print_invalid_move();
        return;
    }
    
    if (*row_1 == *row_2)
    {
        if (!is_clear_path_horizontally(*row_1, *col_1, *col_2))
        {
            print_invalid_move();
            return;
        }
    }
    else if (*col_1 == *col_2)
    {
        if (!is_clear_path_vertically(*col_1, *row_1, *row_2))
        {
            print_invalid_move();
            return;
        }
    }
    
    if (!can_rook_capture(piece, target))
    {
        print_invalid_move();
        return;
    }
    
    swap(row_1, col_1, row_2, col_2);
}
