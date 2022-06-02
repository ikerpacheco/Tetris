/*
** EPITECH PROJECT, 2022
** shorter
** File description:
** shorter functions
*/

#include "../include/my.h"

void shorter(t_game *game, int key, int a)
{
    if (key == 'h')
        help(game, 0);
    if (key == 10) {
        if (a == 0)
            game->status = PLAY;
        if (a == 1)
            help(game, 0);
        if (a == 2)
            help(game, 1);
        if (a == 3) {
            endwin();
            free(game);
            exit(0);
        }
    }
}
