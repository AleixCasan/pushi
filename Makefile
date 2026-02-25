# Makefile for push_swap project

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
INCDIR = includes
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -I $(INCDIR)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus:
	$(CC) $(CFLAGS) -o $(NAME)_bonus $(SRCS) -I $(INCDIR)

.PHONY: all clean fclean re bonus
