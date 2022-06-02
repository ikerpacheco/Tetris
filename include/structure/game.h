/*
** EPITECH PROJECT, 2022
** game
** File description:
** game
*/

#include "../my.h"
#include "./controls.h"
#include "./tetriminos.h"
#include <ncurses.h>

#ifndef GAME
    #define GAME

    typedef struct s_game {
        int level;
        t_controls *controls;
        char **map;
        WINDOW *play;
        WINDOW *next_w;
        WINDOW *stats;
        int score;
        int lines;
        int highscore;
        int full_line;
        int *size;
        int *pos_a;
        int *pos_b;
        int spawn;
        int a;
        int b;
        int right;
        int left;
        int down;
        int crash_line;
        int i;
        int next;
        int status;
        int lose;
        int debug;
        int counter;
        t_tetriminos **pieces;
        t_tetriminos *next_piece;
    } t_game;

#endif /* !GAME */
