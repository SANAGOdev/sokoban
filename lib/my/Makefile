##
## EPITECH PROJECT, 2023
## bsmyls
## File description:
## Makefile
##

CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC = \
	my_compute_power_rec.c \
	my_compute_square_root.c \
	my_is_prime.c \
	my_getnbr.c \
	my_isneg.c \
	my_put_nbr.c \
	my_putchar.c \
	my_putstr.c \
	my_revstr.c \
	my_show_word_array.c \
	my_strcat.c \
	my_strcmp.c \
	my_strcpy.c \
	my_strdup.c \
	my_strlen.c \
	my_strncat.c \
	my_strncpy.c \
	my_swap.c \
	my_sort_int_array.c \
	my_str_to_word_array.c \
	my_find_prime_sup.c \
	my_strstr.c \
	my_strncmp.c \
	my_printf.c \
	my_put_octal.c \
	my_strupcase.c \
	my_put_hex_lower.c \
	my_put_hex_upper.c \
	my_put_pointer.c \
	my_put_unsigned_int.c \
	my_put_float.c \
	my_put_long_float.c \
	my_intlen.c \
	my_put_bin.c \
	my_put_e.c \
	my_put_e_upper.c \

HEADER = my.h

OBJ = $(SRC:.c=.o)

NAME = libmy

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME).a $(OBJ)
	cp $(HEADER) ../../include/
	cp $(NAME).a ../../
	@echo -e "\033[32m[OK]\033[0m": $(NAME)

clean:
	@rm -f $(OBJ)
	@rm -f coding-style-reports.log
	@rm -f *.gcno *.gcda *.gcov vgcore.*
	@echo -e "\033[31m[RM]\033[0m": $(OBJ)

fclean: clean
	@rm -f $(NAME).a
	@rm -f ../../$(NAME).a
	@echo -e "\033[31m[RM]\033[0m": $(NAME)

re: fclean all

.PHONY: all clean fclean re
