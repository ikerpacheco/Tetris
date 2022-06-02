/*
** EPITECH PROJECT, 2022
** spawn pieces
** File description:
** spawn_pieces
*/

#include "../../include/my.h"

int check_first_line(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '*')
            return 1;
        i++;
    }
    return 0;
}

t_game *check_characters(t_game *game, int a, int line)
{
    int b = 0;
    int character = 0;

    for (b = 0; game->map[a][b] != '\0'; b++) {
        if (game->map[a][b] == '*') {
            game->pos_a[line] = a;
            game->pos_a[character] = b;
            line++;
            character++;
        }
    }
    refresh();
    return game;
}

void get_positions(t_game *game)
{
    int a = 0;
    int line = 0;

    if (check_first_line(game->map[0]) == 1 && game->spawn == 0) {
        game->spawn = 1;
        for (a; a < game->size[0]; a++)
            game = check_characters(game, a, line);
    }
}