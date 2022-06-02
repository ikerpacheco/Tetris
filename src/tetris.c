/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** main function for tetris
*/

#include "../include/my.h"

void tetris(int ac, char **av)
{
    t_game *game = init_game();

    in_dir("tetriminos", game);
    if (ac != 1)
        handle_flags(ac, av, game);
    while (1) {
        if (game->status == INTRO)
            get_intro(game);
        else if (game->status == MENU)
            get_menu(game);
        else {
            clear();
            play_tetris(game);
        }
    }
    free(game);
    return;
}
