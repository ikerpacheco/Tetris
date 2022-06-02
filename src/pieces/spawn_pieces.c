/*
** EPITECH PROJECT, 2022
** spawn pieces
** File description:
** spawn_pieces
*/

#include "../../include/my.h"

void check_if_x(t_game *game, int x, int y)
{
    if (game->map[y][x] == 'X')
        game->lose = 1;
}

t_tetriminos *random_piece(t_game *game)
{
    srand(time(NULL));
    int i = rand() % 5;

    while (game->pieces[i]->status != 0)
        i = rand() % 5;
    return game->pieces[i];
}

void spawn_pieces(t_game *game)
{
    t_tetriminos *next = random_piece(game);
    t_tetriminos *piece = game->next_piece;

    for (int y = 0; y < piece->stats[1]; y++)
        for (int x = 0; x < piece->stats[0]; x++)
            check_if_x(game, x, y);
    for (int a = 0; a < piece->stats[1]; a++)
        for (int b = 0; b < piece->stats[0]; b++)
            game->map[a][b] = piece->shape[a][b];
    game->next_piece = next;
}
