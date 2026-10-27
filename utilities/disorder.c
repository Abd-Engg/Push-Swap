#include "../header_files/pushswap.h"

float	disorder(t_stack *s, int size)
{
	float	total_pairs;
	float	mistakes;
	t_node	*curr;

	curr = s->tail;
	total_pairs = ((size - 1) * (size)) / 2.0;
	mistakes = 0;
	while (s->tail)
	{
		curr = s->tail->next;
		while (curr)
		{
			if (s->tail->content > curr->content)
				mistakes++;
			curr = curr->next;
		}
		s->tail = s->tail->next;
	}
	return (mistakes / total_pairs);
}
