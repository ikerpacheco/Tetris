/*
** EPITECH PROJECT, 2022
** clear line
** File description:
** clear_line
*/

#include "../../include/my.h"

void move_map_down(t_game *game)
{
    int a = game->full_line;

    for (a; a > 0; a--)
        game->map[a] = game->map[a - 1];
}

int replace_line(t_game *game, int counter, int a)
{
    if (counter == game->size[1]) {
        counter = 0;
        game->full_line = a;
        move_map_down(game);
        game->lines++;
        game->score += 300;
    }
    return counter;
}

int check_line(char c, int counter)
{
    if (c == 'X')
        counter++;
    
    return counter;
}

void clear_line(t_game *game)
{
    int counter = 0;
    int a = game->size[0] - 1;

    for (a; a >= 0; a--) {
        counter = 0;
        for (int b = game->size[1] - 1; b >= 0; b--) {
            counter = check_line(game->map[a][b], counter);
            counter = replace_line(game, counter, a);
            game->full_line = 0;
        }
    }
}