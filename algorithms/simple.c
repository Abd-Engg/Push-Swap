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

void	selection_sort(t_stack *sa, t_stack *sb, int bench)
{
	int	index;
	int	target;

	target = 0;
	while (sa->size)
	{
		index = pos(sa, target);
		rotate(sa, index, bench);
		pb(sb, sa, bench);
		target++;
	}
	while (sb->size)
		pa(sa, sb, bench);
}
