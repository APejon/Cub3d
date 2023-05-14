# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 15:18:05 by gchernys          #+#    #+#              #
#    Updated: 2023/05/10 15:36:41 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	./debug.c						\
		./main.c						\
		./cub_utils.c					\
		./parsing/parsing.c				\
		./parsing/make_map.c			\
		./parsing/map_validation.c		\
		./parsing/textures_and_colors.c


OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

MLX_FLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit

MLX_PATH = mlx

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C libft
	${MAKE} -C mlx
	${CC} ${CFLAGS} ${OBJS} $(LIBFT) ${MLX_FLAGS} -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -rf *.o
	${MAKE} clean -C libft
	${MAKE} clean -C mlx

fclean: clean
	rm -rf ${NAME}
	${MAKE} fclean -C libft

re: fclean all