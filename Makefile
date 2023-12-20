##
## EPITECH PROJECT, 2023
## sokoban
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -Iinclude -L. -l:./libmy.a -ggdb3 -lncurses

SRC_PATH = src/

SRC = \
	$(SRC_PATH)main.c \
	$(SRC_PATH)map.c \
	$(SRC_PATH)map_utils.c \
	$(SRC_PATH)storage_explorer.c \
	$(SRC_PATH)box_explorer.c \
	$(SRC_PATH)file_reader.c \
	$(SRC_PATH)game.c \
	$(SRC_PATH)game_utils.c \
	$(SRC_PATH)game_fail.c \
	$(SRC_PATH)player.c \
	$(SRC_PATH)player_utils.c \

OBJ = $(SRC:.c=.o)

LIB_PATH = ./lib/my/

NAME = my_sokoban

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB_PATH)
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)
	@echo -e "\033[32m[OK]\033[0m": $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f coding-style-reports.log
	@rm -f *.gcno *.gcda *.gcov vgcore.*
	@echo -e "\033[31m[RM]\033[0m": $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) $@
	@echo -e "\033[31m[RM]\033[0m": $(NAME)

re: fclean all

.PHONY: all clean fclean re
