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
extern int  player_1;
extern int  player_2;

void    print_board(void);
void    parse_input(char *input, int *row_1, int *col_1, int *row_2, int *col_2);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void    is_pawn_move(int *row_1, int *col_1, int *row_2, int *col_2);
void    swap(int *row_1, int *col_1, int *row_2, int *col_2);

#endif