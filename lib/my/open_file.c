/*
** EPITECH PROJECT, 2021
** open_file
** File description:
** opens a read only file
*/

#include "../../include/my.h"

int open_file(char const *filepath)
{
    int result = open(filepath, O_RDONLY);

    if (result == -1) {
        write(2, "Can't open file\n", my_strlen("Can't open file\n"));
        exit(84);
    }
    return (result);
}