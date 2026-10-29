#include "../header_files/pushswap.h"

float	disorder(t_stack *s, int size)
{
	float	total_pairs;
	float	mistakes;
	t_node	*curr;

	curr = s->head;
	total_pairs = ((size - 1) * (size)) / 2.0;
	mistakes = 0;
	while (s->head)
	{
		curr = s->head->prev;
		while (curr)
		{
			if (s->head->content > curr->content)
				mistakes++;
			curr = curr->prev;
		}
		s->head = s->head->prev;
	}
	return (mistakes / total_pairs);
}
