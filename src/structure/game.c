/*
** EPITECH PROJECT, 2022
** game
** File description:
** init game
*/

#include "../../include/my.h"

t_game *init_game(void)
{
    t_game *game = malloc(sizeof(t_game));

    game->controls = init_controls();
    game->size = malloc(sizeof(int) * 3);
    game->size[0] = 20;
    game->size[1] = 10;
    game->i = 0;
    game->full_line = 0;
    game->next_w = newwin(7, 15, LINES / 2 - game->size[0] / 2,
    COLS / 2 + game->size[1] / 2 + 4);
    game->map = NULL;
    game->pos_a = malloc(sizeof(int) * 10);
    game->pos_b = malloc(sizeof(int) * 10);
    game->debug = 0;
    game->crash_line = 0;
    game->a = 0;
    game->b = 0;
    game->spawn = 1;
    game->right = 0;
    game->left = 0;
    game->down = 0;
    game->level = 1;
    game->next = 0;
    game->counter = 0;
    game->status = INTRO;
    game->lose = 0;
    game->score = 500;
    game->highscore = 0;
    game->lines = 0;
    load_highscore(game);
    return game;
}
