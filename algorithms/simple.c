#include "../header_files/pushswap.h"

int	pos(t_stack *s, int target)
{
	t_node	*curr;
	int		counter;

	curr = s->head;
	counter = 0;
	while (curr)
	{
		if (curr->content == target)
			return (counter);
		curr = curr->prev;
		counter++;
	}
	return (-1);
}

void	rotate(t_stack *s, int index)
{
	int	tmp;

	if (index <= 0)
		return ;
	if (index == 1)
		sa(s);
	else if (index <= (int)s->size / 2)
	{
		while (index--)
			ra(s);
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
			rra(s);
	}
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	index;
	int	target;

	target = 0;
	while (stack_a->size)
	{
		index = pos(stack_a, target);
		rotate(stack_a, index);
		pb(stack_b, stack_a);
		target++;
	}
	while (stack_b->size)
		pa(stack_a, stack_b);
}
