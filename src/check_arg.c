/*
** EPITECH PROJECT, 2022
** check_arg
** File description:
** check the different arguments given
*/

#include "../include/my.h"

int check_arg(char *arg)
{
    int answer = 0;

    for (int i = 0; arg[i] != '\0'; i++) {
        answer = checks_if_num(arg[i]);
        if (answer == 1)
            return 1;
    }
    return 0;
}
