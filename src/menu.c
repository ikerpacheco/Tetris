/*
** EPITECH PROJECT, 2022
** menu
** File description:
** menu
*/

#include "../include/my.h"

void less_printing(int light)
{
    char *first = "/---------------------------\\";
    char *second = "\\---------------------------/";
    char *choices[4] = {"Play", "Help", "Programmers", "Exit"};
    int i = 0;

    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen(first) / 2, first);
    while (i < 4) {
        if (i == light)
            attron(A_STANDOUT);
        mvprintw(LINES / 2 + i, COLS / 2 -
        my_strlen(choices[i]) / 2, choices[i]);
        attroff(A_STANDOUT);
        i += 1;
    }
    mvprintw(LINES / 2 + 5, COLS / 2 - my_strlen(second) / 2, second);
}

void print_all(t_game *game, int light)
{
    attron(A_BOLD);
    attron(A_STANDOUT);
    mvprintw(LINES / 2 - 12, COLS / 2 - my_strlen("Tetris Game") / 2,
    "Tetris Game");
    attroff(A_BOLD);
    attroff(A_STANDOUT);
    mvprintw(LINES / 2 - 8, COLS / 2 -
    my_strlen("[Q] to leave the game") / 2, "[Q] to leave the game");
    mvprintw(LINES / 2 - 9, COLS / 2 -
    my_strlen("[H] for some help") / 2, "[H] for some help");
    mvprintw(LINES / 2 - 4, COLS / 2 -
    my_strlen("Choose Option ") / 2, "Choose Option ");
    less_printing(light);
    refresh();
}

int get_highlight(t_game *game, int a)
{
    int key = getch();

    if (key == KEY_DOWN) {
        a += 1;
        if (a > 3)
            a = 0;
    }
    if (key == KEY_UP) {
        a -= 1;
        if (a < 0)
            a = 3;
    }
    if (key == 'q') {
        endwin();
        exit(0);
    }
    shorter(game, key, a);
    return a;
}

int get_menu(t_game *game)
{
    int light = 0;

    initscr();
    curs_set(FALSE);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    while (game->status == MENU) {
        clear();
        menu_tight();
        print_intro(-20);
        print_all(game, light);
        light = get_highlight(game, light);
        refresh();
    }
    endwin();
}
