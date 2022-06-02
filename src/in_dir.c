/*
** EPITECH PROJECT, 2022
** in_dir
** File description:
** in dir
*/

#include "../include/my.h"

char **do_rest(t_game *game, char **buf, char *name, struct dirent *d)
{
    buf[game->i] = get_file(name);
    game->pieces[game->i] = create_tetriminos(buf[game->i], d->d_name);
    game->i++;
    return buf;
}

int in_dir(char *dir, t_game *game)
{
    struct dirent *d;
    DIR *dh = opendir(dir);
    int size = get_size();
    char *name = NULL;
    char **buf = malloc(sizeof(char *) * size + 1);

    game->pieces = malloc(sizeof(t_tetriminos) * size + 1);
    if (dh == NULL)
        return 84;
    while ((d = readdir(dh)) != NULL) {
        if (!(d->d_name[0] != '.'))
            continue;
        name = my_strcat("tetriminos/", d->d_name);
        if (access(name, R_OK) == 0)
            buf = do_rest(game, buf, name, d);
    }
    free(buf);
    closedir(dh);
    return 0;
}
