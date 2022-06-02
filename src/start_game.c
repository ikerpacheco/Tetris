/*
** EPITECH PROJECT, 2022
** start game
** File description:
** start_game
*/

#include "my.h"

void start_game(t_game *game)
{
    game->next_piece = random_piece(game);
    refresh();
    timeout(0);
    spawn_pieces(game);
}