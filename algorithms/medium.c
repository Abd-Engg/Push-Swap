#include "../header_files/pushswap.h"

int	chunk_size(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	stage_a(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk;
	int	start;
	int	counter;

	chunk = chunk_size(stack_a->size);
	start = 0;
	while (stack_a->size)
	{
		counter = 0;
		while (counter < chunk && stack_a->size)
		{
			if (stack_a->head->content >= start
				&& stack_a->head->content < start + chunk)
			{
				pb(stack_b, stack_a);
				counter++;
			}
			else
				ra(stack_a);
		}
		start += chunk;
	}
}

void	rotate_b(t_stack *s, int index)
{
	int	tmp;

	if (index <= 0)
		return ;
	if (index <= (int)s->size / 2)
	{
		while (index--)
			rb(s);
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
			rrb(s);
	}
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	target;

	stage_a(stack_a, stack_b);
	target = stack_b->size - 1;
	while (stack_b->size)
	{
		rotate_b(stack_b, pos(stack_b, target));
		pa(stack_a, stack_b);
		target--;
	}
}
