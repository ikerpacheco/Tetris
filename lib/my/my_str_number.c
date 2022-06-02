/*
** EPITECH PROJECT, 2022
** my_str_isnumber
** File description:
** checks if the str only has numbers or not
*/

#include "../../include/my.h"

int my_str_isnumber(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i += 1;
    }
    return 0;
}
