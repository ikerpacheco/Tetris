/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Return the length of a given string.
*/

#include "../../include/my.h"

char **my_arrdup(char **arr)
{
    int len = my_arrlen(arr);
    char **new_arr = malloc(sizeof(char *) * (len + 1));
    int i = 0;
    if (arr == NULL || new_arr == NULL)
        return (NULL);
    while (i < len) {
        new_arr[i] = my_strdup(arr[i]);
        if (new_arr[i] == NULL)
            return (NULL);
        i++;
    }
    new_arr[i] = NULL;
    return (new_arr);
}
