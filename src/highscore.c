/*
** EPITECH PROJECT, 2022
** highscore
** File description:
** highscore
*/

#include "my.h"

void save_highscore(t_game *game)
{
    FILE *file = fopen("highscore.txt", "w");
    if (file == NULL)
        return;
    if (game->score > game->highscore)
        game->highscore = game->score;
    fprintf(file, "%d", game->highscore);
    fclose(file);
}

void load_highscore(t_game *game)
{
    FILE *file = fopen("highscore.txt", "r");
    if (file == NULL)
        return;
    fscanf(file, "%d", &game->highscore);
    fclose(file);
}