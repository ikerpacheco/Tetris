/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Return the length of a given string.
*/

#include "../../include/my.h"

int my_arrlen(char **arr)
{
    int length = 0;

    while (arr[length] != NULL) {
        length++;
    }
    return (length);
}
