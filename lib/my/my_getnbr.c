/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** Number
*/

#include <stdio.h>

void my_put_nbr(int);

int checks_if_num(char c)
{
    if (c <= '9' && c >= '0') {
        return 0;
    } else {
        return 1;
    }
}

int my_getnbr(char const *str)
{
    int nb = 0;
    int x = 0;
    int i = 0;

    while (str[x] != '\0') {
        while (checks_if_num(str[i]) == 1) {
            i++;
            x++;
        }
        nb = nb * 10;
        nb = (nb + (str[x] - 48));
        x++;
        if (checks_if_num(str[x]) == 1 && str[i - 1] == '-')
            return (nb * -1);
        if (checks_if_num(str[x]) == 1)
            return nb;
    }
    return nb;
}
