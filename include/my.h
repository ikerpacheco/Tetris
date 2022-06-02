/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my h
*/

#ifndef MY_H_
    #define MY_H_

    #define INTRO    0
    #define MENU    1
    #define PLAY    2

    #include "structure/game.h"
    #include "structure/controls.h"
    #include "structure/tetriminos.h"

    #include <stdarg.h>
    #include <stdio.h>
    #include <getopt.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <pwd.h>
    #include <fcntl.h>
    #include <grp.h>
    #include <sys/wait.h>
    #include <time.h>
    #include <ncurses.h>
    #include <stdbool.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/System/Vector2.h>

    int handle_flags(int ac, char **av, t_game *game);

    void tetris(int ac, char **av);

    void save_highscore(t_game *game);

    void load_highscore(t_game *game);

    t_game *init_game(void);

    void debug_mode(t_game *game);

    void display_key(int ch);

    void start_game(t_game *game);

    t_controls *init_controls(void);

    void printing_extra(void);

    int play_tetris(t_game *game);

    void spawn_pieces(t_game *game);

    t_tetriminos *random_piece(t_game *game);

    void move_gravity(t_game *game);

    void clear_line(t_game *game);

    void replacer(t_game *game);

    int right_checker(t_game *game);

    int left_checker(t_game *game);

    int down_checker(t_game *game);

    void check_win(t_game *game);

    void check_movement(int key, t_game *game);

    void print_map(t_game *game);

    t_game *move_right(t_game *game);

    t_game *move_left(t_game *game);

    void reset_line(char *str);

    void get_positions(t_game *game);

    void display_help(void);

    t_game *move_up(t_game *game);

    void get_intro(t_game *game);

    int get_menu(t_game *game);

    void shorter(t_game *game, int key, int a);

    void menu_tight(void);

    void help(t_game *game, int status);

    void print_intro(int line);

    void info(void);

    t_game *move_down(t_game *game);

    int in_dir(char *dir, t_game *game);

    int get_size(void);

    char *get_file(char *filename);

    void new_tetriminos(char **buffer, t_game *game, int size);

    t_tetriminos *create_tetriminos(char *piece, char *naming);

    t_tetriminos *get_stats(char *piece, t_tetriminos *tetriminos);

    char **get_piece(char *str, int *stats);

    t_game *generate_map(t_game *game);

    int my_getnbr(char const *str);

    void my_printarr(char **arr);

    void tight(char *path, char **tab);

    int my_tablen(char **array);

    char *my_strdup(char const *src);

    int checks_if_num(char c);

    char *my_strncpy(char *dest, char *src, int n);

    int my_atoi(char *str);

    int error_handling(int ac, char **av);

    int my_put_nbr(int nb);

    char *my_strcat(char *dest, char const *src);

    char **my_2Dmalloc(char **array, int size);

    char **allocate_mem(char **array, int *stats);

    char **str_to_array_two(char *str, int n, int *stat);

    char **str_to_array(char *str, int n);

    char **my_arrdup(char **arr);

    int my_arrlen(char **arr);

    char **my_str_to_word(char *str);

    void my_putchar(char c);

    int my_strnlen(char const *str);

    void my_putstr(char const *str);

    int my_strcmp(char const *s1, char const *s2);

    int my_numlen(long nb);

    int my_strlen(char const *str);

    int my_str_isnumber(char *str);

#endif /* MY_H_ */
