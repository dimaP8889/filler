#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpogrebn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 13:58:31 by dpogrebn          #+#    #+#              #
#    Updated: 2018/04/23 13:58:32 by dpogrebn         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ./dpogrebn.filler
LIBA = libft/libft.a
SRC = src/dpogrebn.filler.c src/ft_fill.c src/ft_put_del.c src/extra_fc.c
HEADER = src/dpogrebn.filler.h
FLAGS = -Wall -Wextra -Werror
CC = gcc

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA)