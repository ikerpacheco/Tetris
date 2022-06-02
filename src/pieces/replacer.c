/*
** EPITECH PROJECT, 2022
** spawn pieces
** File description:
** spawn_pieces
*/

#include "../../include/my.h"

void replace_character(t_game *game, int a, int b)
{
    if (game->map[a][b] == '*')
        game->map[a][b] = 'X';
}

void replacer(t_game *game)
{
    int a = 0;
    int b = 0;

    for (a; a < game->size[0]; a++) {
        for (b = 0; b < game->size[1]; b++)
            replace_character(game, a, b);
    }
}