/*
** EPITECH PROJECT, 2022
** tetris
** File description:
** tetris
*/

#include "../include/my.h"

void game_loop(t_game *game, int key)
{
    check_movement(key, game);
    print_map(game);
    wnoutrefresh(game->play);
    wnoutrefresh(game->stats);
    wnoutrefresh(game->next_w);
    doupdate();
    right_checker(game);
    left_checker(game);
    clear_line(game);
}

void get_boxes(t_game *game)
{
    timeout(10000);
    initscr();
    noecho();
    game = generate_map(game);
    print_map(game);
    refresh();
    box(game->play, 0, 0);
    box(game->next_w, 0, 0);
    box(game->stats, 0, 0);
}

void prepare_boxes(t_game *game)
{
    int x = 0;
    int y = 0;

    getmaxyx(game->next_w, x, y);
    mvwprintw(game->next_w, 0, y / 2 -
    my_strlen("| Next |") / 2, "| Next |");
    getmaxyx(game->play, x, y);
    mvwprintw(game->play, 0, y / 2 -
    my_strlen("| Game |") / 2, "| Game |");
    getmaxyx(game->stats, x, y);
    mvwprintw(game->stats, 0, y / 2 -
    my_strlen("| Statistics |") / 2, "| Statistics |");
    mvwprintw(game->stats, 3, 1, "Highscore:");
    mvwprintw(game->stats, 4, 1, "Score:");
    mvwprintw(game->stats, 8, 1, "Lines:");
    mvwprintw(game->stats, 9, 1, "Level:");
}

void mainloop(t_game *game)
{
    int key;
    WINDOW *win;
    int i = 0;
    float seconds = 0;
    start_game(game);
    while (game->lose == 0) {
        for (int j = 0; j < game->next_piece->stats[1]; j++)
            mvwprintw(game->next_w, 1 + j, 1, game->next_piece->shape[j]);
        key = getch();
        if (seconds > 2000 - game->level * 200) {
            move_gravity(game);
            seconds = 0;
        }
        game_loop(game, key);
        seconds += 0.1;
        refresh();
    }
    save_highscore(game);
    free(game);
    endwin();
    exit(0);
}

int play_tetris(t_game *game)
{
    game->play = newwin(game->size[0] + 1, game->size[1] + 2,
    LINES / 2 - game->size[0] / 2, COLS / 2 - game->size[1] / 2);
    game->next_w = newwin(7, 15, LINES / 2 - game->size[0] / 2,
    COLS / 2 + game->size[1] / 2 + 4);
    game->stats = newwin(15, 30, LINES / 2 - game->size[0] / 2,
    COLS / 2 - game->size[1] / 2 - 32);
    get_boxes(game);
    prepare_boxes(game);
    refresh();
    printing_extra();
    wnoutrefresh(game->play);
    wnoutrefresh(game->stats);
    wnoutrefresh(game->next_w);
    doupdate();
    mainloop(game);
    endwin();
}
