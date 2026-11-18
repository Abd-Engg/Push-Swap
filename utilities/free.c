#include "../header_files/definitions.h"

void	free_stack(t_stack *s)
{
	t_node	*cur;
	t_node	*tmp;

	cur = s->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->prev;
		free(tmp);
	}
	free(s);
}

void	free_all(t_stack *a, t_stack *b, int *arr)
{
	free_stack(a);
	free_stack(b);
	free(arr);
}
