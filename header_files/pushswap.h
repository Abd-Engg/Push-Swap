
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_ops
{
	int	p;
	int	s;
	int	ss;
	int	rot;
	int	revrot;
	int	rot_both;
	int	revrot_both;
}					t_ops;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	t_ops			op;
	size_t			size;
}					t_stack;

void		del_node(t_stack *s);
t_node		*add_new_node(t_stack *s, int content);
t_stack		*init_stack(void);
void		push(t_stack *s1, t_stack *s2);
void		swap(t_stack *s1);
void		rot(t_stack *s1);
void		revrot(t_stack *s1);
void		ra(t_stack *sa, int bench);
void		pa(t_stack *sa, t_stack *sb, int bench);
void		sa(t_stack *sa, int bench);
void		sb(t_stack *sb, int bench);
void		pb(t_stack *sb, t_stack *sa, int bench);
void		rb(t_stack *sb, int bench);
void		rra(t_stack *sa, int bench);
void		rrb(t_stack *sb, int bench);
void		ss(t_stack *sa, t_stack *sb, int bench);
void		rr(t_stack *sa, t_stack *sb, int bench);
void		rrr(t_stack *sa, t_stack *sb, int bench);
void		sort(int arr[], int l, int mid, int r);
int			*fill_arr(int arr[], int size, int idx);
void		binary_search(t_stack *s, int *arr);
void		merge_sort(int *arr, int l, int r);

#endif
