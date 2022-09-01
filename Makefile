NAME = philo
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c utils.c time.c get.c

OBJ = $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all re clean fclean