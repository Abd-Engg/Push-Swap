#include "../header_files/pushswap.h"

float	disorder(t_stack *s, int size)
{
	float	total_pairs;
	float	mistakes;
	t_node	*curr;
	t_node *c;

	if (!size)
		return (0);
	c = s->head;
	curr = s->head;
	total_pairs = ((size - 1) * (size)) / 2.0;
	mistakes = 0;
	while (c)
	{
		curr = c->prev;
		while (curr)
		{
			if (c->content > curr->content)
				mistakes++;
			curr = curr->prev;
		}
		c = c->prev;
	}
	return (mistakes / total_pairs);
}

t_strategy _disorder(t_stack *a)
{
	float dis;

	dis = disorder(a, a->size);
	if (dis < 0.2)
		return (simple);
	else if(dis < 0.5)
		return (medium);
	else
		return (complex);
}
