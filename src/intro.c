/*
** EPITECH PROJECT, 2022
** menu
** File description:
** get the tetris menu
*/

#include "../include/my.h"

void menu_tight(void)
{
    while (LINES < 28 || COLS < 50) {
        clear();
        sleep(1);
        mvprintw(LINES / 2, COLS / 2 - 11, "terminal too tight [!]");
        refresh();
    }
}

void shorter_printing(void)
{
    attron(A_STANDOUT);
    mvprintw(LINES / 2 + 3, COLS / 2 - my_strlen
    ("Press [ENTER] to start the game") / 2,
    "Press [ENTER] to start the game");
    attroff(A_STANDOUT);
}

void print_intro(int line)
{
    char *str = " __          __  _                   ";

    str = my_strcat(str, "         _          _______   _        _     ");
    mvprintw(LINES / 2 + line - 4, COLS / 2 - 42, str);
    str = " \\ \\        / / | |                       ";
    str = my_strcat(str, "   | |        |__   __| | |      (_)    ");
    mvprintw(LINES / 2 + line - 3, COLS / 2 - 42, str);
    str = "  \\ \\  /\\  / ___| | ___ ___  _ __ ___   ";
    str = my_strcat(str, "___  | |_ ___      | | ___| |_ _ __ _ ___ ");
    mvprintw(LINES / 2 +line - 2, COLS / 2 - 42, str);
    str = "   \\ \\/  \\/ / _ | |/ __/ _ \\| '_ ` _ \\ /";
    str = my_strcat(str, " _ \\ | __/ _ \\     | |/ _ | __| '__| / __|");
    mvprintw(LINES / 2 + line - 1, COLS / 2 - 42, str);
    str = "    \\  /\\  |  __| | (_| (_) | | | | | |";
    str = my_strcat(str, "  __/ | || (_) |    | |  __| |_| |  | \\__ \\");
    mvprintw(LINES / 2 + line, COLS / 2 - 42, str);
    str = "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|";
    str = my_strcat(str, "\\___|  \\__\\___/     |_|\\___|\\__|_|  |_|___/");
    mvprintw(LINES / 2 + line + 1, COLS / 2 - 42, str);
}

void init_colors(WINDOW *menu)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    wbkgd(stdscr, COLOR_PAIR(1));
}

void get_intro(t_game *game)
{
    int light = 0;
    WINDOW *menu;
    int status = 0;

    initscr();
    curs_set(FALSE);
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    init_colors(menu);
    timeout(0);
    while (game->status == INTRO) {
        menu_tight();
        shorter_printing();
        print_intro(0);
        light = getch();
        if (light == 10)
            game->status = MENU;
    }
    endwin();
}
