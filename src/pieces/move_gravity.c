/*
** EPITECH PROJECT, 2022
** move_right
** File description:
** move_right
*/

#include "../../include/my.h"

void check_border(t_game *game, int a, int b)
{
    if (game->map[a][b] == '*' && a == game->size[0] - 1) {
        replacer(game);
        game->score += 150;
        if (game->score == 950 || game->score == 1400 ||
        game->score == 1850 || game->score == 2300)
            game->level += 1;
        spawn_pieces(game);
    }
}

void check_collision(t_game *game, int a, int b)
{
    if (game->map[a][b] == '*' && game->map[a + 1][b] == 'X') {
        replacer(game);
        game->score += 150;
        if (game->score == 950 || game->score == 1400 ||
        game->score == 1850 || game->score == 2300)
            game->level += 1;
        spawn_pieces(game);
    }
}

void go_down_character(t_game *game, int a, int b)
{
    if (game->map[a][b] == '*') {
        game->map[a][b] = ' ';
        game->map[a + 1][b] = '*';
    }
}

void move_gravity(t_game *game)
{
    for (int a = game->size[0] - 1; a >= 0; a--)
        for (int b = game->size[1] - 1; b >= 0; b--) {
            check_border(game, a, b);
            check_collision(game, a, b);
        }
    for (int a = game->size[0] - 1; a >= 0; a--)
        for (int b = game->size[1] - 1; b >= 0; b--)
            go_down_character(game, a, b);
}