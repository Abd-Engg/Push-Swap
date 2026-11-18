NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  algorithms/complex.c \
		  algorithms/medium.c \
		  algorithms/simple.c \
		  operations/ops_a.c \
		  operations/ops_b.c \
		  operations/ops_both.c \
		  operations/stack_ops.c \
		  utilities/disorder.c \
		  utilities/print_benchmark.c \
		  utilities/sort_args.c \
		  utilities/stack.c \
		  utilities/free.c \
		  utilities/parsing/checking.c \
		  utilities/parsing/parsing.c \
		  utilities/parsing/Set_Data.c \
		  imports/libft/ft_atoi.c \
		  imports/libft/ft_isalpha.c \
		  imports/libft/ft_isdigit.c \
		  imports/libft/ft_itoa.c \
		  imports/libft/ft_lstadd_back.c \
		  imports/libft/ft_lstadd_front.c \
		  imports/libft/ft_lstclear.c \
		  imports/libft/ft_lstdelone.c \
		  imports/libft/ft_lstnew.c \
		  imports/libft/ft_lstlast.c \
		  imports/libft/ft_split.c \
		  imports/libft/ft_strcmp.c \
		  imports/libft/ft_strjoin.c \
		  imports/libft/ft_strlcpy.c \
		  imports/libft/ft_strlen.c \
		  imports/printf/ft_printf.c \
		  imports/printf/ft_putchar.c \
		  imports/printf/ft_putfloat.c \
		  imports/printf/ft_puthexa.c \
		  imports/printf/ft_putnbr.c \
		  imports/printf/ft_putptr.c \
		  imports/printf/ft_putstr.c \
		  imports/printf/ft_putunsigned.c

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
