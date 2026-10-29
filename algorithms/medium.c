#include "../header_files/pushswap.h"

int	chunk_size(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	stage_a(t_stack *sa, t_stack *sb, int bench)
{
	int	chunk;
	int	start;
	int	counter;

	chunk = chunk_size(sa->size) * 3 / 2;
	start = 0;
	while (sa->size)
	{
		counter = 0;
		while (counter < chunk && sa->size)
		{
			if (sa->head->content >= start
				&& sa->head->content < start + chunk)
			{
				pb(sb, sa, bench);
				counter++;
			}
			else
				ra(sa, bench);
		}
		start += chunk;
	}
}

void	rotate_b(t_stack *s, int index, int bench)
{
	int	tmp;

	if (index <= 0)
		return ;
	if (index <= s->size / 2)
	{
		while (index--)
			rb(s, bench);
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
			rrb(s, bench);
	}
}

void	medium_sort(t_stack *sa, t_stack *sb, int bench)
{
	int	target;

	stage_a(sa, sb, bench);
	target = sb->size - 1;
	while (sb->size)
	{
		rotate_b(sb, pos(sb, target), bench);
		pa(sa, sb, bench);
		target--;
	}
}
