/*
** EPITECH PROJECT, 2022
** move_right
** File description:
** move_right
*/

#include "../../include/my.h"

int check_left_column(t_game *game)
{
    int a = 0;
    int b = 0;

    for (a; a < game->size[0]; a++) {
        if (game->map[a][b] == '*')
            return 1;
    }
    return 0;
}

int left_checker(t_game *game)
{
    if (check_left_column(game) == 1)
        game->left = 1;
    else
        game->left = 0;
}