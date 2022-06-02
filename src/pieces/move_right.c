/*
** EPITECH PROJECT, 2022
** move_right
** File description:
** move_right
*/

#include "../../include/my.h"

void move_character_right(t_game *game, int a, int b)
{
    if ((game->map[a][b] == '*' && game->map[a][b + 1] == ' ') && b != game->size[1] && game->right != 1) {
        game->right = 0;
        game->map[a][b] = ' ';
        game->map[a][b + 1] = '*';
    }
}

t_game *move_right(t_game *game)
{
    int a = 0;
    int b = game->size[1] - 1;

    for (a; a < game->size[0]; a++) {
        for (b = game->size[1] - 1; b >= 0; b--)
            move_character_right(game, a, b);
    }
    return game;
}