# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afakili <ahmetcanfakili50@gmail.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 04:12:53 by afakili           #+#    #+#              #
#    Updated: 2022/09/04 04:12:53 by afakili          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc -g -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror
SRCS = actions.c get.c main.c time.c utils.c dining.c

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -ggdb

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all re clean fclean