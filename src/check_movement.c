/*
** EPITECH PROJECT, 2022
** check_movement
** File description:
** check_movement
*/

#include "../include/my.h"

void check_movement(int key, t_game *game)
{
    switch(key) {
        case KEY_RIGHT:
            game = move_right(game);
            break;
        case KEY_LEFT:
            game = move_left(game);
            break;
        case KEY_DOWN:
            game = move_down(game);
            break;
        case 'q':
            free(game);
            endwin();
            exit(0);
            break;
    }
}