/*
** EPITECH PROJECT, 2022
** flags
** File description:
** handle the flags for the tetris project
*/

#include "../include/my.h"

void map_size(char *arg, t_game *game)
{
    char **array = my_2Dmalloc(array, 4);

    array = my_str_to_word(arg);
    if (array[0][0] == '-' || array[1][0] == '-')
        return;
    game->size[0] = my_getnbr(array[0]);
    game->size[1] = my_getnbr(array[1]);
}

int more_flags(char c, char *arg, t_controls *controls)
{
    switch (c) {
        case 'h': display_help();
            exit(0);
        case 'd': controls->drop = my_getnbr(arg);
            break;
        case 't': controls->turn = my_getnbr(arg);
            break;
        case 'p': controls->pause = my_getnbr(arg);
            break;
        case 'q': controls->quit = my_getnbr(arg);
            break;
        case 'r': controls->right = my_getnbr(arg);
            break;
        case 'l': controls->left = my_getnbr(arg);
            break;
        case '?':
            return 84;
    }
}

int get_flags(char c, t_game *game, char *arg)
{
    if (c == 'D') {
        game->debug = 0;
        game->debug += 1;
        return game->debug;
    }
    if (arg == NULL || my_strcmp(arg, " ") == 0)
        return 84;
    if (arg[0] == '-')
        return 84;
    switch (c) {
        case 0: map_size(arg, game);
            break;
        case 'L': game->level = my_getnbr(arg);
            break;
        case 'w': game->next = 1;
            break;
        default: more_flags(c, arg, game->controls);
            break;
    }
    return 0;
}

int find_flags(struct option long_options[], t_game *game,
int ac, char **av)
{
    int c = 0;
    int option_index = 0;

    while ((c = getopt_long(ac, av, "hL:l:r:t:d:q:p:wD",
    long_options, &option_index)) != -1) {
        if (c == -1)
            return 84;
        get_flags(c, game, optarg);
        option_index += 1;
    }
    if (game->debug == 1) {
        debug_mode(game);
        exit(0);
    }
    return 0;
}

int handle_flags(int ac, char **av, t_game *game)
{
    int c = 0;
    int option_index = 0;
    static struct option long_options[] = {
        {"help", no_argument, NULL, 'h'},
        {"level", required_argument, NULL, 'L'},
        {"key-left", required_argument, NULL, 'l'},
        {"key-right", required_argument, NULL, 'r'},
        {"key-turn", required_argument, NULL, 't'},
        {"key-drop", required_argument, NULL, 'd'},
        {"key-quit", required_argument, NULL, 'q'},
        {"key-pause", required_argument, NULL, 'p'},
        {"map-size", required_argument, NULL, 0},
        {"without-next", no_argument, NULL, 'w'},
        {"debug", no_argument, NULL, 'D'},
        {0, 0, 0, 0},
    };

    find_flags(long_options, game, ac, av);
    return 0;
}
