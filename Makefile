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
SRC = dpogrebn.filler.c
HEADER = dpogrebn.filler.h
FLAGS = -Wall -Wextra -Werror
CC = gcc

comp:
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIBA)