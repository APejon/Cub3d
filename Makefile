# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gchernys <gchernys@42abudhabi.ae>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 15:11:41 by gchernys          #+#    #+#              #
#    Updated: 2023/04/23 18:41:23 by gchernys         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := cub3D

CFLAGS := -Wall -Werror -Wextra -g -fsanitize=address

FLAGS := -rcs

mlx := ./mlx/libmlx.a

FILES :=	./main.c		\
			./error_check.c	\
			./get_map.c		\
			./utils.c
		
OBJECTS := $(FILES:.c=.o)

LIBFT := cd libft && make

LIB := libft/libft.a

$(NAME)	:
		$(LIBFT)
		make -C ./mlx
		gcc $(CFLAGS) -o cub3D $(FILES) $(LIB) $(mlx) -framework OpenGL -framework AppKit

all : $(NAME)

clean :
		rm -f $(OBJS)
		cd libft && make clean
		make clean -C mlx

fclean : clean
		rm -f $(NAME)
		cd libft && make fclean
		make clean -C mlx

re : fclean all

.PHONY : all clean fclean re