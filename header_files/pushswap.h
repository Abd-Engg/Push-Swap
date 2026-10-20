#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>

typedef struct		s_node
{
	int				content;
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

t_node		*new_node(t_stack *s, int content);
t_stack		*init_stack();
void		push(t_stack *s1, t_stack *s2);
void		swap(t_stack **s1);
void		rot(t_stack **s1);
void		revrot(t_stack **s1);

#endif
