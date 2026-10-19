#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>

typedef struct		s_node
{
	int				content;
	int				index;
	struct	s_node	*next;
	struct	s_node	*prev;
}					t_node;

typedef struct 		s_ops
{
	int	p;
	int	s;
	int	ss;
	int	rot;
	int	revrot;
	int	rot_both;
	int	revrot_both;
}					t_ops;

typedef struct 		s_stack
{
	t_node			*head;
	t_node			*tail;
	t_ops			op;
	size_t			size;
}					t_stack;

#endif
