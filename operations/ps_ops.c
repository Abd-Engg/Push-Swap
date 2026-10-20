#include "../header_files/pushswap.h"

void	push(t_stack *s1, t_stack *s2) //pa -> push(stackA, stackB);
{
	s1->head->next = s2->head;
	s2->head = NULL;
	s1->head = s1->head->next;
	s1->size += 1;
	s2->size -= 1;
	s1->op.p += 1;
}

void	swap(t_stack **s1) //sa -> swap(**stackA)
{
	t_node	*prev;
	t_node	*pprev;
	t_node	*head;

	head = (*s1)->head;
	prev = head->prev;
	pprev = prev->prev;
	if (pprev)
		pprev->next = (*s1)->head;
	else
	 (*s1)->tail = head;
	prev->prev = head;
	head->prev = pprev;
	head->next = prev;
	prev->next = NULL;
	(*s1)->head = prev;
}
