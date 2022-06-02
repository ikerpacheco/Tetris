/*
** EPITECH PROJECT, 2022
** move_right
** File description:
** move_right
*/

#include "my.h"

void move_character_down(t_game *game, int a, int b)
{
    if (a == game->size[0] - 1)
        return;
    if (game->map[a][b] == '*' && game->map[a + 1][b] != 'X') {
        game->map[a][b] = ' ';
        game->map[a + 1][b] = '*';
    }
}

t_game *move_down(t_game *game)
{
    for (int a = game->size[0] - 1; a >= 0; a--)
        for (int b = game->size[1] - 1; b >= 0; b--)
            move_character_down(game, a, b);
    return game;
}
