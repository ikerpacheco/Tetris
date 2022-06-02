/*
** EPITECH PROJECT, 2022
** my_tablen
** File description:
** get the y-len of a 2D array
*/

#include "../../include/my.h"

int my_tablen(char **array)
{
    int y = 0;

    while (array[y] != NULL)
        y += 1;
    return y;
}
