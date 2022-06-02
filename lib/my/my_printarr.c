/*
** EPITECH PROJECT, 2021
** printarray
** File description:
** x
*/

#include "../../include/my.h"

void my_printarr(char **arr)
{
    int a = 0;

    while (arr[a] != NULL) {
        my_putstr(arr[a]);
        my_putstr("\n");
        a++;
    }
}