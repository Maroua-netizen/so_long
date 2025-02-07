# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmounsif <mmounsif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 10:21:17 by mmounsif          #+#    #+#              #
#    Updated: 2025/02/07 13:43:03 by mmounsif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

SRC = main.c \
	src/my_mlx_pixel_put.c \
	src/get_map.c \
	src/ft_strlen.c \
	src/ft_strjoin.c \
	src/ft_strchr.c \
	src/ft_strdup.c \
	src/ft_substr.c \
	src/get_next_line.c \
	src/map_line_count.c \
	src/ft_calloc.c \
	src/ft_bzero.c \
	src/check_map.c \
	src/exit_start_check.c \
	src/collectibles_count.c \
	src/walls_check.c 

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