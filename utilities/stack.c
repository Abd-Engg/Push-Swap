#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

t_stack	*init_stack()
{
	t_stack *stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->op.p = 0;
	stack->op.s = 0;
	stack->op.rot = 0;
	stack->op.revrot = 0;
	stack->op.ss = 0;
	stack->op.rot_both = 0;
	stack->op.revrot_both = 0;
	return (stack);
}

t_node	*new_node(t_stack *s, int content)
{
	t_node *node = malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	if (!(s->tail))
	{
		s->tail = node;
		node->prev = NULL;
	}
	else
	{
		s->head->next = node;
		node->prev = s->head;
	}
	s->head = node;
	(s->size)++;
	return (node);
}
