# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmitriy1 <dmitriy1@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/10 19:58:55 by dmitriy1          #+#    #+#              #
#    Updated: 2018/05/12 15:21:24 by dmitriy1         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visual
LIBA = ../libft/libft.a
SRC = visual.c ft_out.c
HEADER = visual.h
FLAGS = -Wall -Wextra -Werror
FLAGS_MLX = -lmlx
MLX = ../minilibx/libmlx.a
FLAG_FRAME = -framework
FRAMEWORK = $(FLAG_FRAME) OpenGL $(FLAG_FRAME) AppKit

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA) $(MLX) $(FRAMEWORK)