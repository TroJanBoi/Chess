#include "../include/chess.h"

void    parse_input(char *input, int *row_1, int *col_1, int *row_2, int *col_2)
{
    char    **p = ft_split(input, ' ');

    if (strlen(p[0]) != 2 || strlen(p[1]) != 3)
        return ;
    *col_1 = input[0] - 'a'; // a-h → 0-7
    *row_1 = input[1] - '1'; // 1-8 → 0-7
    *col_2 = input[3] - 'a';
    *row_2 = input[4] - '1';
    free(*p);
}