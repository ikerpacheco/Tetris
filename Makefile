##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## makefile
##

SRC	=	src/main.c	\
		src/tetris.c	\
		src/flags.c	\
		src/get_file.c	\
		src/get_tetriminos.c	\
		src/structure/controls.c	\
		src/structure/tetriminos.c	\
		src/structure/game.c \
		src/check_arg.c	\
		src/debug_mode.c	\
		lib/my/my_printarr.c \
		src/get_piece.c \
		lib/my/my_arrdup.c \
		src/menu.c	\
		src/key_adapter.c	\
		src/highscore.c \
		lib/my/my_arrlen.c \
		src/shorter.c	\
		src/in_dir.c	\
		src/printing_extra.c \
		lib/my/str_to_array.c \
		src/help.c	\
		src/intro.c	\
		src/play_tetris.c \
		src/map/generate_map.c \
		src/map/print_map.c \
		src/pieces/spawn_pieces.c \
		src/pieces/move_down.c \
		src/pieces/move_right.c \
		src/pieces/move_left.c \
		src/check_movement.c \
		src/pieces/get_positions.c \
		src/pieces/move_gravity.c \
		src/map/clear_line.c \
		src/pieces/replacer.c \
		src/pieces/right_checker.c \
		src/pieces/left_checker.c \
		src/start_game.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CURSE =	-lncurses

CFLAGS = -g -I./include

FLAGS =	-Wall -Werror -Wextra

GREEN   =   \033[0;32m

NONE    =   \033[0m

SIGNATURE	=	─=≡Σ((( つ◕ل͜◕)つ   GET MAKEFILED   ─=≡Σ((( つ◕ل͜◕)つ

all:	$(NAME)

$(NAME):	$(OBJ)
	@	cd lib/my && make
	@	echo -e "\n\n$(GREEN)$(SIGNATURE)$(NONE)\n\n"
	@	gcc -o $(NAME) $(OBJ) $(FLAGS) $(CURSE) -L lib/my/ -lmy $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	cd lib/my/ && make fclean
	rm -f $(NAME)

re:	fclean all
