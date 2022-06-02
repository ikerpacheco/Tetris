/*
** EPITECH PROJECT, 2022
** debug_mode
** File description:
** all the debug mode functions
*/

#include "../include/my.h"

void keys_debug(t_controls *controls)
{
    my_putstr("Key left: ");
    display_key(controls->left);
    my_putstr("Key right: ");
    display_key(controls->right);
    my_putstr("Key turn: ");
    display_key(controls->turn);
    my_putstr("Key drop: ");
    display_key(controls->drop);
    my_putstr("Key quit: ");
    display_key(controls->quit);
    my_putstr("Key pause: ");
    display_key(controls->pause);
}

void stats_debug(t_game *game)
{
    if (game->next == 0)
        my_putstr("Next: Yes\n");
    else
        my_putstr("Next: No\n");
    my_putstr("Level: ");
    my_put_nbr(game->level);
    my_putchar('\n');
    my_putstr("Size: ");
    my_put_nbr(game->size[0]);
    my_putchar('*');
    my_put_nbr(game->size[1]);
    my_putchar('\n');
    my_putchar('\n');
}

void tetriminos_debug(t_tetriminos **pieces, int counter)
{
    my_putstr("Number of tetriminos: ");
    my_put_nbr(counter);
    my_putchar('\n');
    for (int i = 0; i < counter; i++) {
        my_putstr("Tetriminos ");
        my_putchar(39);
        my_putstr(pieces[i]->name);
        my_putchar(39);
        my_putchar(':');
        if (pieces[i]->status == 0) {
            my_putstr(" size ");
            my_put_nbr(pieces[i]->stats[0]);
            my_putchar('*');
            my_put_nbr(pieces[i]->stats[1]);
            my_putstr(", color ");
            my_put_nbr(pieces[i]->stats[2]);
            my_putchar('\n');
            my_printarr(pieces[i]->shape);
        } else
            my_putstr(" error\n");
    }
}

void debug_mode(t_game *game)
{
    int error_counter = 0;

    for (int i = 0; i < game->i; i++) {
        if (game->pieces[i]->status >= 1)
            error_counter += 1;
    }
    if (error_counter >= game->i) {
        exit(84);
    }
    keys_debug(game->controls);
    stats_debug(game);
    tetriminos_debug(game->pieces, game->i);
    return;
}
