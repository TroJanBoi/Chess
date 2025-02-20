#include "../include/chess.h"

void get_promotion_piece(char *promotion_piece) {
    printf("Enter the piece you want to promote to (Q, R, B, N): ");
    fgets(promotion_piece, 10, stdin);

    size_t len = strlen(promotion_piece);
    if (len > 0 && promotion_piece[len - 1] == '\n') {
        promotion_piece[len - 1] = '\0';
    }
}

char validate_promotion_piece(char piece, char input_piece) {
    if (piece == 'p') {
        if (input_piece == 'q' || input_piece == 'r' || input_piece == 'b' || input_piece == 'n')
            return input_piece;
    } else if (piece == 'P') {
        if (input_piece == 'Q' || input_piece == 'R' || input_piece == 'B' || input_piece == 'N')
            return input_piece;
    }
    printf(GREEN"Invalid piece, defaulting to Queen\n"RESET);
    return (piece == 'p') ? 'q' : 'Q';
}

void is_promotion_pawn(int row, int col) {
    char promotion_piece[10];
    char piece = board[row][col];

    get_promotion_piece(promotion_piece);
    board[row][col] = validate_promotion_piece(piece, promotion_piece[0]);
}


int     is_valid_pawn_move(int row_1, int col_1, int row_2, int col_2, char piece, char target)
{
    int row_diff = row_2 - row_1;
    int col_diff = abs(col_2 - col_1);

    if (piece == 'p') 
    {
        if ((row_diff == -1 && col_diff == 0 && target == ' ') ||
            (row_diff == -1 && col_diff == 1 && target >= 'A' && target <= 'Z') ||
            (row_1 == 6 && row_2 == 4 && col_1 == col_2 && target == ' '))
            return 1;
    }
    else if (piece == 'P') 
    {
        if ((row_diff == 1 && col_diff == 0 && target == ' ') ||
            (row_diff == 1 && col_diff == 1 && target >= 'a' && target <= 'z') ||
            (row_1 == 1 && row_2 == 3 && col_1 == col_2 && target == ' '))
            return 1;
    }
    return 0;
}

void    is_pawn_move(int *row_1, int *col_1, int *row_2, int *col_2)
{
    char piece = board[*row_1][*col_1];
    char target = board[*row_2][*col_2];

    if (is_valid_pawn_move(*row_1, *col_1, *row_2, *col_2, piece, target))
    {
        capturing(row_1, col_1, row_2, col_2);
        if (*row_2 == 0 || *row_2 == 7)
            is_promotion_pawn(*row_2, *col_2);
    }
    else
        printf(RED"Invalid move\n"RESET);
}