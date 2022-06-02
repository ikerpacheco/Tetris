/*
** EPITECH PROJECT, 2022
** tetriminos
** File description:
** tetriminos
*/

#include "../my.h"

#ifndef TETRIMINOS
    #define TETRIMINOS

    typedef struct s_tetriminos {
        char **shape;
        int orientation;
        int *stats;
        char *name;
        int status;
    } t_tetriminos;

#endif /* !TETRIMINOS */
