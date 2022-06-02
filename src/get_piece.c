/*
** EPITECH PROJECT, 2022
** get_tetriminos
** File description:
** get the tetriminos
*/

#include "../include/my.h"

void pass_values(t_game *game, char **arr, int x)
{
    int a = 0;
    int j = 0;

    for (a; arr[a] != NULL; a++)
        for (int b = 0; arr[a][b] != '\0'; b++) {
            game->pieces[x]->shape[a][b] = arr[a][b];
            x++;
        }
}

char **get_piece(char *str, int *stats)
{
    int i = 0;
    char **arr = NULL;

    while (str[i] != '\n' && str[i] != '\0')
        i++;
    i++;
    arr = str_to_array_two(str, i, stats);
    return arr;
}
