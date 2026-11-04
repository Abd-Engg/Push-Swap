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

void	rotate(t_stack *s, int index, int bench)
{
	int	tmp;

	if (index <= 0)
		return ;
	if (index == 1)
		sa(s, bench);
	else if (index <= (int)s->size / 2)
	{
		while (index--)
			ra(s, bench);
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
			rra(s, bench);
	}
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b, int bench)
{
	int	index;
	int	target;

	target = 0;
	while (stack_a->size)
	{
		index = pos(stack_a, target);
		rotate(stack_a, index, bench);
		pb(stack_b, stack_a, bench);
		target++;
	}
	while (stack_b->size)
		pa(stack_a, stack_b, bench);
}
