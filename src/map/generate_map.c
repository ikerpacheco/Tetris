/*
** EPITECH PROJECT, 2022
** clear line
** File description:
** clear_line
*/

#include "../../include/my.h"

t_game *generate_map(t_game *game)
{
    int a = 0;
    int b = 0;

    game->map = malloc(sizeof(char *) * game->size[0] + 1);
    for (a; a < game->size[0]; a++) {
        game->map[a] = malloc(sizeof(char) * game->size[1] + 1);
        for (b = 0; b < game->size[1]; b++)
            game->map[a][b] = ' ';
        game->map[a][b] = '\0';
    }
    game->map[a] = NULL;
    return game;
}