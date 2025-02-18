#include "../include/chess.h"

void swap(int *row_1, int *col_1, int *row_2, int *col_2)
{
    board[*row_2][*col_2] = board[*row_1][*col_1];
    board[*row_1][*col_1] = ' ';
}

void check_piece(int *row_1, int *col_1, int *row_2, int *col_2)
{
    char    piece = board[*row_1][*col_1];

    if (piece == 'p' || piece == 'P')
        is_pawn_move(row_1, col_1, row_2, col_2);
    else if (piece == 'r' || piece == 'R')
        is_rook_move(row_1, col_1, row_2, col_2);
    else if (piece == 'n' || piece == 'N')
        is_knight_move(row_1, col_1, row_2, col_2);
    else if (piece == 'b' || piece == 'B')
        is_bishop_move(row_1, col_1, row_2, col_2);
    else if (piece == 'q' || piece == 'Q')
        is_queen_move(row_1, col_1, row_2, col_2);
    else
        print_invalid_move();
}

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

int main(void)
{
    char    input[10];
    int     row_1, col_1, row_2, col_2;
    int     round = 0;

    while (1)
    {
        print_board();
        printf("Enter move: ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "exit\n", 4) == 0)
            break;
        parse_input(input, &row_1, &col_1, &row_2, &col_2);
        if (is_valid_move(row_1, col_1, row_2, col_2) == SUCCESS)
            check_piece(&row_1, &col_1, &row_2, &col_2);
        else
            printf(RED"Invalid move\n"RESET);
    }
}