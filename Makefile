NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  $(wildcard algorithms/*.c) \
		  $(wildcard operations/*.c) \
		  $(wildcard utilities/*.c) \
		  $(wildcard utilities/parsing/*.c) \
		  $(wildcard imports/libft/*.c) \
		  $(wildcard imports/printf/*.c)

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
