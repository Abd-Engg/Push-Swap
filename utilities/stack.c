#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->op.p = 0;
	stack->op.s = 0;
	stack->op.rot = 0;
	stack->op.revrot = 0;
	stack->op.ss = 0;
	stack->op.rot_both = 0;
	stack->op.revrot_both = 0;
	stack->size = 0;
	return (stack);
}

t_node	*new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_node	*add_new_node(t_stack *s, int content)
{
	t_node	*node;

	node = new_node(content);
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

void	del_node(t_stack *s)
{
	t_node	*tmp;

	if (!s->head)
		return ;
	if (s->tail == s->head)
	{
		free(s->head);
		s->head = NULL;
		s->tail = NULL;
		s->size -= 1;
		return ;
	}
	tmp = s->head;
	s->head = s->head->prev;
	s->head->next = NULL;
	s->size -= 1;
	free(tmp);
}
