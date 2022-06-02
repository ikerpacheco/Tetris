/*
** EPITECH PROJECT, 2022
** clear line
** File description:
** clear_line
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i])
        i++;
    i--;
    while (j < i) {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp;
        i--;
        j++;
    }
    return (str);
}

char *my_itoa(int nb)
{
    int i = 0;
    int n = nb;
    char *str = malloc(sizeof(char) * 12);

    if (n < 0) {
        str[i] = '-';
        i++;
        n = -n;
    }
    while (n > 0) {
        str[i] = n % 10 + '0';
        n = n / 10;
        i++;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

void print_map(t_game *game)
{
    for (int a = 0; a < game->size[0]; a++) {
        char *score = my_itoa(game->score);
        char *highscore = my_itoa(game->highscore);
        char *lines = my_itoa(game->lines);
        char *level = my_itoa(game->level);
        mvwprintw(game->play, a, 1, game->map[a]);
        mvwprintw(game->stats, 4, 8, score);
        mvwprintw(game->stats, 3, 12, highscore);
        if (game->lines > 0)
            mvwprintw(game->stats, 8, 8, lines);
        else
            mvwprintw(game->stats, 8, 8, "0");
        if (game->level < 5)
            mvwprintw(game->stats, 9, 8, level);
        else
            mvwprintw(game->stats, 9, 8, "Max Level");
    }
}
