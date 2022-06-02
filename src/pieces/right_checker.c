/*
** EPITECH PROJECT, 2022
** move_right
** File description:
** move_right
*/

#include "../../include/my.h"

int check_right_column(t_game *game)
{
    int a = 0;
    int b = game->size[1] - 1;

    for (a; a < game->size[0]; a++) {
        if (game->map[a][b] == '*')
            return 1;
    }
    return 0;
}

int right_checker(t_game *game)
{
    if (check_right_column(game) == 1)
        game->right = 1;
    else
        game->right = 0;
}