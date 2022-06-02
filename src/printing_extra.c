/*
** EPITECH PROJECT, 2022
** printing extra
** File description:
** printing_extra
*/

#include "my.h"

void extra_printing(char *str)
{
    str = " /__/:/\\:\\   \\  \\:\\/:/ /:/ /__/:/\\:\\   \\  \\";
    str = my_strcat(str, ":\\/:::::/    \\  \\:\\/\\ \\  \\:\\/:/~/:/");
    mvprintw(LINES / 2 - 17, COLS / 2 - my_strlen(str) / 2, str);
    str = " \\__\\/  \\:\\   \\  \\::/ /:/  \\__\\/  \\:\\   \\  \\";
    str = my_strcat(str, "::/~~~~      \\__\\::/  \\  \\::/ /:/ ");
    mvprintw(LINES / 2 - 16, COLS / 2 - my_strlen(str) / 2, str);
    str = "      \\  \\:\\   \\  \\:\\/:/        \\  \\:\\";
    str = my_strcat(str, "   \\  \\:\\          /__/:/    \\__\\/ /:/  ");
    mvprintw(LINES / 2 - 15, COLS / 2 - my_strlen(str) / 2, str);
    str = "       \\__\\/    \\  \\::/          \\__\\/    ";
    str = my_strcat(str, "\\  \\:\\         \\__\\/       /__/:/   ");
    mvprintw(LINES / 2 - 14, COLS / 2 - my_strlen(str) / 2, str);
    str = "                 \\__\\/                    ";
    str = my_strcat(str, " \\__\\/                     \\__\\/    ");
    mvprintw(LINES / 2 - 13, COLS / 2 - my_strlen(str) / 2, str);
}

void printing_extra(void)
{
    char *str = "                  ___                      ";

    str = my_strcat(str, " ___                       ___     ");
    mvprintw(LINES / 2 - 23, COLS / 2 - my_strlen(str) / 2, str);
    str = "      ___        /  /\\          ___        /  ";
    str = my_strcat(str, "/\\        ___          /  /\\    ");
    mvprintw(LINES / 2 - 22, COLS / 2 - my_strlen(str) / 2, str);
    str = "     /  /\\      /  /:/_        /  /\\      /  /:";
    str = my_strcat(str, ":\\      /  /\\        /  /:/_   ");
    mvprintw(LINES / 2 - 21, COLS / 2 - my_strlen(str) / 2, str);
    str = "    /  /:/     /  /:/ /\\      /  /:/     /";
    str = my_strcat(str, "  /:/\\:\\    /  /:/       /  /:/ /\\  ");
    mvprintw(LINES / 2 - 20, COLS / 2 - my_strlen(str) / 2, str);
    str = "   /  /:/     /  /:/ /:/_    /  /:/     /  /";
    str = my_strcat(str, ":/~/:/   /__/::\\      /  /:/ /::\\ ");
    mvprintw(LINES / 2 - 19, COLS / 2 - my_strlen(str) / 2, str);
    str = "  /  /::\\    /__/:/ /:/ /\\  /  /::\\    /__";
    str = my_strcat(str, "/:/ /:/___ \\__\\/\\:\\__  /__/:/ /:/\\:\\");
    mvprintw(LINES / 2 - 18, COLS / 2 - my_strlen(str) / 2, str);
    extra_printing(str);
}