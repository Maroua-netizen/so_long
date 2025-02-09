# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 10:21:17 by mmounsif          #+#    #+#              #
#    Updated: 2025/02/09 18:50:31 by mmounsif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
	src/mini_libft/ft_strlen.c \
	src/mini_libft/ft_strjoin.c \
	src/mini_libft/ft_strchr.c \
	src/mini_libft/ft_strdup.c \
	src/mini_libft/ft_substr.c \
	src/mini_libft/ft_calloc.c \
	src/mini_libft/ft_bzero.c \
	src/mini_libft/ft_putchar.c \
	src/mini_libft/ft_puthex.c \
	src/mini_libft/ft_putnbr.c \
	src/mini_libft/ft_putptr.c \
	src/mini_libft/ft_putstr.c \
	src/mini_libft/ft_putunbr.c \
	src/ft_printf.c \
	src/get_next_line.c \
	src/get_map.c \
	src/free_map.c \
	src/map_line_count.c \
	src/check_map.c \
	src/collectibles_count.c \
	src/flood_check.c \
	src/display_background.c \
	src/display_map.c \
	src/key_hook.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re