/*
** EPITECH PROJECT, 2022
** key_adapter
** File description:
** key adapter
*/

#include "../include/my.h"

char *get_name(int index)
{
    const char *folder = "./tetriminos";
    DIR *rep = opendir(folder);
    struct dirent *reader;
    int i = 0;

    if (rep == NULL)
        return 0;
    while ((reader = readdir(rep))) {
        if (reader->d_name[0] == '.')
            continue;
        if (i == index)
            return (my_strdup(reader->d_name));
        i++;
    }
    closedir(rep);
    free(reader);
    return NULL;
}

int str_to_key(char *str)
{
    if (my_strcmp(str, "(space)") == 0)
        return (int)' ';
    if (my_strcmp(str, "KEY_TOP") == 0)
        return 259;
    if (my_strcmp(str, "KEY_BOT") == 0)
        return 258;
    if (my_strcmp(str, "KEY_LEFT") == 0)
        return 260;
    if (my_strcmp(str, "KEY_RIGHT") == 0)
        return 261;
    return 0;
}

char *key_to_str(int ch)
{
    if (ch == ' ')
        return " ";
    if (ch == 259)
        return "KEY_TOP";
    if (ch == 258)
        return "KEY_BOT";
    if (ch == 260)
        return "KEY_LEFT";
    if (ch == 261)
        return "KEY_RIGHT";
    return NULL;
}

void display_key(int ch)
{
    if (key_to_str(ch) == NULL) {
        my_putchar(ch);
        my_putstr(" (");
        my_put_nbr(ch);
        my_putstr(")\n");
    } else {
        my_putstr(key_to_str(ch));
        my_putstr(" (");
        my_put_nbr(ch);
        my_putstr(")\n");
    }
}

