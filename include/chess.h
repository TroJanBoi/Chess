#ifndef CHESS_H
# define CHESS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BOARD_SIZE 8
# define SUCCESS 0
# define FAILURE 1
# define RED     "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define RESET   "\x1B[0m"


extern char board[BOARD_SIZE][BOARD_SIZE];
extern int has_moved[8][8];


typedef struct  s_piece
{
    char    piece;
    int     row;
    int     col;
}               t_piece;

void    print_board(void);
void    parse_input(char *input, int *row_1, int *col_1, int *row_2, int *col_2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    capturing(int *row_1, int *col_1, int *row_2, int *col_2);
void    print_invalid_move(void);
int     is_valid_move(int row_1, int col_1, int row_2, int col_2);
void    swap_castle(int *row_1, int *col_1, int *row_2, int *col_2);
int     is_checkmate(int king_row, int king_col);

// pieces
void    is_pawn_move(int *row_1, int *col_1, int *row_2, int *col_2);
void    is_rook_move(int *row_1, int *col_1, int *row_2, int *col_2);
void    is_knight_move(int *row_1, int *col_1, int *row_2, int *col_2);
void    is_bishop_move(int *row_1, int *col_1, int *row_2, int *col_2);
void    is_queen_move(int *row_1, int *col_1, int *row_2, int *col_2);
void    is_king_move(int *row_1, int *col_1, int *row_2, int *col_2);

int     is_valid_rook_move(int row_1, int col_1, int row_2, int col_2);
int     is_clear_path_horizontally(int row, int col_1, int col_2);
int     is_clear_path_vertically(int col, int row_1, int row_2);
int     is_valid_bishop_move(int row_1, int col_1, int row_2, int col_2);

#endif