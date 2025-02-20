#include "../include/chess.h"

int has_moved[8][8] = {0}; // 0 = not moved, 1 = moved

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

int main(void)
{
    char    input[10];
    int     row_1, col_1, row_2, col_2;
    int     round = 0;

    while (1)
    {
        char    king_status = find_king();
        if (king_status == 'k')
        {
            printf("White wins\n");
            break;
        }
        else if (king_status == 'K')
        {
            printf("Black wins\n");
            break;
        }
        print_board();
        printf("Enter move: ");
        fgets(input, sizeof(input), stdin);
        if (strncmp(input, "exit\n", 5) == 0)
            break;
        if (find_king() == 'k')
        {
            printf("White wins\n");
            break;
        }
        else if (find_king() == 'K')
        {
            printf("Black wins\n");
            break;
        }
        if (strlen(input) == 6)
        {
            parse_input(input, &row_1, &col_1, &row_2, &col_2);
            if (is_valid_move(row_1, col_1, row_2, col_2) == SUCCESS)
                check_piece(&row_1, &col_1, &row_2, &col_2);
            else
                printf(RED"Invalid move\n"RESET);
        }
        else
            printf(RED"Invalid Move\n"RESET);
    }
}