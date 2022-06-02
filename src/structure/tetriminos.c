/*
** EPITECH PROJECT, 2022
** tetriminos
** File description:
** tetriminos
*/

#include "../../include/my.h"

char **allocate_mem(char **array, int *stats)
{
    array = malloc(stats[1] * sizeof(char *) + 1);

    for (int i = 0; i < stats[0]; i++) {
        array[i] = malloc(stats[0] * sizeof(char) + 1);
    }
    return (array);
}

int check_shape(char **shape, int *stats)
{
    int max = 0;
    int i = 0;

    for (i = 0; shape[i]; i++) {
        for (int y = 0; shape[i][y] != '\0'; y++) {
            if (y > max)
                max = y;
            if (shape[i][y] != '*' && shape[i][y] != ' ' && shape[i][y] != '\n')
                return 1;
        }
    }
    if (stats[0] < 0 || stats[1] < 0 || stats[2] <= 0 && stats[2] >= 10)
        return 1;
    if (i != stats[1] || (max + 1) != stats[0])
        return 1;
    return 0;
}

t_tetriminos *create_tetriminos(char *piece, char *naming)
{
    t_tetriminos *tetriminos = malloc(sizeof(t_tetriminos));

    tetriminos->name = malloc(sizeof(char) * my_strlen(naming) + 1);
    for (int i = 0; naming[i] != '.'; i++)
        tetriminos->name[i] = naming[i];
    tetriminos->status = 0;
    tetriminos = get_stats(piece, tetriminos);
    if (tetriminos->status != 0)
        return tetriminos;
    tetriminos->orientation = 0;
    if (tetriminos->stats[0] < 0 || tetriminos->stats[1] < 0 ||
    tetriminos->stats[2] <= 0 || tetriminos->stats[2] >= 10) {
        tetriminos->status += 1;
        return tetriminos;
    }
    tetriminos->shape = get_piece(piece, tetriminos->stats);
    tetriminos->status += check_shape(tetriminos->shape, tetriminos->stats);
    return tetriminos;
}
