#include "include/chess.h"

void    parse_input(char *input, int *row_1, int *col_1, int *row_2, int *col_2)
{
    char    **p = ft_split(input, ' ');

    if (strlen(p[0]) != 2 || strlen(p[1]) != 3)
        return ;
    *col_1 = input[0] - 'a';  // a-h → 0-7
    *row_1 = input[1] - '1'; // 1-8 → 0-7
    *col_2 = input[3] - 'a';
    *row_2 = input[4] - '1';
    printf(YELLOW"input: %s\n"RESET, p[0]);
    printf(CYAN"row_1: %d\n"RESET, *row_1);
    printf(CYAN"col_1: %d\n"RESET, *col_1);
    printf(RED"-------------\n"RESET);
    printf(YELLOW"input: %s"RESET, p[1]);
    printf(CYAN"row_2: %d\n"RESET, *row_2);
    printf(CYAN"col_2: %d\n"RESET, *col_2);
    free(*p);
}