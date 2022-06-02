/*
** EPITECH PROJECT, 2022
** controls
** File description:
** init controls
*/

#include "../../include/my.h"

t_controls *init_controls(void)
{
    t_controls *controls = malloc(sizeof(t_controls));

    controls->left = KEY_LEFT;
    controls->right = KEY_RIGHT;
    controls->turn = KEY_UP;
    controls->drop = KEY_DOWN;
    controls->quit = 'q';
    controls->pause = 'p';
    return controls;
}
