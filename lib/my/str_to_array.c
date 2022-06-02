/*
** EPITECH PROJECT, 2022
** str to array
** File description:
** str_to_array
*/

#include "../../include/my.h"

char **my_alloc(char **array, int size)
{
    array = malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++) {
        array[i] = malloc(100 * sizeof(char));
    }
    return (array);
}

char **str_to_array_two(char *str, int n, int *stat)
{
    char **array = my_2Dmalloc(array, stat[1]);
    int x = 0;
    int y = 0;

    array[y] = malloc(sizeof(char *) * stat[0] + 1);
    while (str[n] != '\0') {
        while (str[n] != '\0' && str[n] != '\n') {
            array[y][x] = str[n];
            n += 1;
            x += 1;
        }
        array[y][x] = '\0';
        n += 1;
        x = 0;
        y += 1;
    }
    array[y] = NULL;
    return (array);
}

char **str_to_array(char *str, int n)
{
    int len = my_strlen(str);
    char **array = my_2Dmalloc(array, len);
    int x = 0;
    int y = 0;

    while (str[n] != '\0') {
        while (str[n] != '\0' && str[n] != '\n') {
            array[y][x] = str[n];
            n += 1;
            x += 1;
        }
        array[y][x] = '\0';
        n += 1;
        x = 0;
        y += 1;
    }
    array[y] = NULL;
    return (array);
}