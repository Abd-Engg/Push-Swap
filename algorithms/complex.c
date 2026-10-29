#include "../header_files/pushswap.h"

int	count(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 2;
		i++;
	}
	return (i);
}

void	complex(t_stack *stack_a, t_stack *stack_b, int bench)
{
	int	iterations;
	int	i;
	int	curr;
	int	j;

	iterations = count(stack_a->size - 1);
	i = 0;
	j = 0;
	while (i < iterations)
	{
		j = 0;
		while (j < stack_a->size)
		{
			curr = stack_a->head->content;
			if (!((curr >> i) & 1))
				pb(stack_b, stack_a, bench);
			else
				ra(stack_a, bench);
			j++;
		}
		while (stack_b->head)
			pa(stack_a, stack_b, bench);
		i++;
	}
}
