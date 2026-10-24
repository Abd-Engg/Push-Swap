#include "../header_files/pushswap.h"
#include "../header_files/ft_printf.h"

void	print(char *str, t_stack *s)
{
		t_node	*cur;

	cur = s->tail;
	ft_printf("%s", str);
	while (cur)
	{
		ft_printf("%d ", cur->content);
		cur = cur->next;
	}
	ft_printf("\n");

}

int	count(int n)
{
	int	i;

	i = 0;
	while(n)
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
			ft_printf("curr: %d\n", (curr >> i) & 1);
			if ((curr >> i) & 1)
				pb(stack_b, stack_a, bench);
			else
				ra(stack_a, bench);
			j++;
			print("stack_a before: ", stack_a);
			print("stack_b: ", stack_b);
			ft_printf("\n");

		}
		//print("stack_a before: ", stack_a);
		//print("stack_b: ", stack_b);
		while (stack_b->head)
			pa(stack_a, stack_b, bench);
		i++;
		print("stack_a after: ", stack_a);
	}
}
