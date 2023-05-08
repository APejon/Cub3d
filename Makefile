# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 01:12:29 by gchernys          #+#    #+#              #
#    Updated: 2023/05/08 15:18:56 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address

CC := gcc

FLAGS := -rcs

mlx := ./mlx/libmlx.a

FILES :=	./main.c							\
			./parsing/parsing.c					\
			./parsing/make_map.c				\
			./cub_utils.c						\
			./debug.c							\
			./parsing/map_validation.c			\
			./parsing/textures_and_colors.c
		
OBJECTS := $(FILES:.c=.o)

LIBFT := cd libft && make

LIB := libft/libft.a

$(NAME)	: $(OBJECTS)
		$(LIBFT)
		$(CC) $(CFLAGS) -o cub3D $(FILES) $(LIB)

all : $(NAME)

clean :
		rm -f $(OBJECTS)
		cd libft && make clean

fclean : clean
		rm -f $(NAME)
		cd libft && make fclean

re : fclean all

.PHONY : all clean fclean re