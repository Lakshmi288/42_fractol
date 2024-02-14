# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lps <lps@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 09:02:47 by lps               #+#    #+#              #
#    Updated: 2024/01/16 12:46:07 by lps              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

FILES = main.c mandelbrot.c julia.c events.c utils.c utils2.c ft_atof.c

OBJ = $(FILES:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

MLX = libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	cd mlx && make
	$(CC) $(CFLAGS) $(OBJ) -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(MLX)
	make clean -sC ./mlx

fclean: clean
	rm -f $(NAME)

re: fclean all
