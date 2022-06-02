/*
** EPITECH PROJECT, 2022
** get_tetriminos
** File description:
** get the tetriminos
*/

#include "../include/my.h"

int check_cond(char array)
{
    if (checks_if_num(array) == 0)
        return 1;
    return 0;
}

int check_array(char **array)
{
    int i = 0;
    int number = 0;

    while (array[i]) {
        for (int y = 0; array[i][y] != '\0'; y++)
            number = check_cond(array[i][y]);
        i += 1;
    }
    if (number == 0)
        return 1;
    if (i != 3)
        return 1;
}

t_tetriminos *get_stats(char *piece, t_tetriminos *tetriminos)
{
    char *tmp = malloc(sizeof(char) * my_strlen(piece) + 1);
    char **array = my_2Dmalloc(array, 4);
    int *stats = malloc(sizeof(int) * 4);

    for (int i = 0; piece[i] != '\n' && piece[i] != '\0'; i++)
        tmp[i] = piece[i];
    tmp[my_strlen(tmp)] = '\0';
    array = my_str_to_word(tmp);
    if (check_array(array) == 1) {
        tetriminos->status += 1;
        return tetriminos;
    }
    for (int i = 0; array[i] != NULL; i++) {
        stats[i] = my_getnbr(array[i]);
    }
    tetriminos->stats = stats;
    return tetriminos;
}
