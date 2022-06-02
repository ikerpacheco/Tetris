/*
** EPITECH PROJECT, 2022
** help
** File description:
** help
*/

#include "../include/my.h"

void info(void)
{
    char *first = "/----------------------------\\";
    char *second = "\\----------------------------/";
    char *leave = "Press anything to return to menu\n";

    mvprintw(LINES / 2 - 7, COLS / 2 -
    my_strlen("PROGRAMMERS\n") / 2, "PROGRAMMERS\n");
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(first) / 2, first);
    mvprintw(LINES / 2 - 3, COLS / 2 -
    my_strlen("The Programmers of this game are\n") / 2,
    "The Programmers of this game are\n");
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen
    ("Aymeric Fisselier\n") / 2, "Aymeric Fisselier\n");
    mvprintw(LINES / 2, COLS / 2 - my_strlen
    ("Instagram : @aymbcn\n") / 2, "Instagram : @aymbcn\n");
    mvprintw(LINES / 2 + 2, COLS / 2 - my_strlen
    ("Iker Pacheco\n") / 2, "Iker Pacheco\n");
    mvprintw(LINES / 2 + 3, COLS / 2 - my_strlen
    ("Instagram : @ikerpacheco\n") / 2, "Instagram : @ikerpacheco\n");
    mvprintw(LINES / 2 + 5, COLS / 2 - my_strlen(second) / 2, second);
    mvprintw(LINES / 2 + 6, COLS / 2 - my_strlen(leave) / 2, leave);
}

void printing(void)
{
    char *first = "/----------------------------\\";
    char *second = "\\----------------------------/";
    char *leave = "Press anything to return to menu\n";

    attron(A_STANDOUT);
    mvprintw(LINES / 2 - 7, COLS / 2 - my_strlen("HELP\n") / 2, "HELP\n");
    attroff(A_STANDOUT);
    mvprintw(LINES / 2 - 5, COLS / 2 - my_strlen(first) / 2, first);
    attron(A_BOLD);
    mvprintw(LINES / 2 - 3, COLS / 2 -
    my_strlen("The game is Tetris\n") / 2, "The game is Tetris\n");
    mvprintw(LINES / 2 - 2, COLS / 2 - my_strlen
    ("You probably already know it\n") / 2, "You probably already know it\n");
    mvprintw(LINES / 2 - 1, COLS / 2 - my_strlen
    ("No need to explain then :)\n") / 2, "No need to explain then :)\n");
    mvprintw(LINES / 2, COLS / 2 - my_strlen
    ("Have Fun\n") / 2, "Have Fun\n");
    mvprintw(LINES / 2 + 2, COLS / 2 - my_strlen(second) / 2, second);
    mvprintw(LINES / 2 + 4, COLS / 2 - my_strlen(leave) / 2, leave);
}

void help(t_game *game, int status)
{
    int key = 0;

    clear();
    if (status == 0)
        printing();
    else
        info();
    refresh();
    attroff(A_BOLD);
    timeout(100000);
    key = getch();
    menu_tight();
    if (key == KEY_ENTER) {
        clear();
        get_menu(game);
        return;
    }
}

void shorter_print(char *str)
{
    str = "  -d --key-drop={K}\tDROP the tetromino ";
    str = my_strcat(str, "using the K key (def: down arrow)\n");
    my_putstr(str);
    str = "  -q --key-quit={K}\tQUIT the game ";
    str = my_strcat(str, "using the K key (def: 'q' key)\n");
    my_putstr(str);
    str = "  -p --key-pause={K}\tPAUSE/RESTART the game ";
    str = my_strcat(str, "using the K key (def: space bar)\n");
    my_putstr(str);
    str = "  --map-size={row,col}\tSet the numbers of rows";
    str = my_strcat(str, " and columns of the map (def: 20,10)\n");
    my_putstr(str);
    my_putstr("  -w --without-next\tHide next tetrimino (def: false)\n");
    my_putstr("  -D --debug\t\tDebug mode (def: false)\n");
}

void display_help(void)
{
    char *str = "  -L --level={num}\t";

    my_putstr("Usage: ./tetris [options]\nOptions:\n");
    my_putstr("  --help\t\tDisplay this help\n");
    str = my_strcat(str, "Start Tetris at level num (def: 1)\n");
    my_putstr(str);
    str = "  -l --key-left={K}\tMove the tetrimi";
    str = my_strcat(str, "no LEFT using the K key (def: left arrow)\n");
    my_putstr(str);
    str = "  -r --key-right={K}\tMove the tetrimino";
    str = my_strcat(str, " RIGHT using the K key (def: right arrow)\n");
    my_putstr(str);
    str = "  -t --key-turn={K}\tTURN the tetrimino clockwise 90d";
    str = my_strcat(str, " using the K key (def: top arrow)\n");
    my_putstr(str);
    shorter_print(str);
}
