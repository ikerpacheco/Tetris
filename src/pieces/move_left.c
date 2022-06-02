/*
** EPITECH PROJECT, 2022
** move_right
** File description:
** move_right
*/

#include "../../include/my.h"

void move_character_left(t_game *game, int a, int b)
{
    if ((game->map[a][b] == '*' && game->map[a][b - 1] == ' ') && b != 0 && game->left != 1) {
        game->left = 0;
        game->map[a][b] = ' ';
        game->map[a][b - 1] = '*';
    }
}

t_game *move_left(t_game *game)
{
    int a = 0;
    int b = 0;

    for (a; a < game->size[0]; a++) {
        for (b = 0; b < game->size[1]; b++)
            move_character_left(game, a, b);
    }

    return game;
}