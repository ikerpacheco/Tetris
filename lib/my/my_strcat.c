/*
** EPITECH PROJECT, 2021
** MY_STR_CAT
** File description:
** Concatenates two strings
*/

#include "../../include/my.h"

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int i = 0;
    int j = 0;

    while (dest[i]) {
        new[i] = dest[i];
        i++;
    }
    while (src[j]) {
        new[i] = src[j];
        i++;
        j++;
    }
    new[i] = '\0';
    return new;
}
