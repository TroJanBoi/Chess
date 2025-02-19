#include "../include/chess.h"

int has_moved[8][8] = {0}; // 0 = not moved, 1 = moved

void swap_castle(int *king_row, int *king_col, int *rook_row, int *rook_col) {
    int new_king_col = (*rook_col == 7) ? 6 : 2;
    int new_rook_col = (*rook_col == 7) ? 5 : 3;

    board[*king_row][new_king_col] = board[*king_row][*king_col];
    board[*king_row][*king_col] = ' ';
    board[*rook_row][new_rook_col] = board[*rook_row][*rook_col];
    board[*rook_row][*rook_col] = ' ';
    *king_col = new_king_col;
    *rook_col = new_rook_col;
}


void capturing(int *row_1, int *col_1, int *row_2, int *col_2)
{
    board[*row_2][*col_2] = board[*row_1][*col_1];
    board[*row_1][*col_1] = ' ';
    
    has_moved[*row_2][*col_2] = 1;
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
    else if (piece == 'k' || piece == 'K')
        is_king_move(row_1, col_1, row_2, col_2);
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