# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbackaer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/24 17:44:40 by qbackaer          #+#    #+#              #
#    Updated: 2019/04/25 18:33:17 by qbackaer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror --pedantic
NAME = fillit
INCLUDES = fillit.h
SRCS = fillit.c parsing.c list.c
OBJS = fillit.o parsing.o list.o

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $^ -I. ./libft/libft.a -o fillit

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I. -c $^

clean:
	rm -rf *.o
	make fclean -C ./libft

fclean: clean
	rm -rf fillit

re: fclean all
