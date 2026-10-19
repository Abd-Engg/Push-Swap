#include "../header_files/pushswap.h"

void	push(t_stack *s1, t_stack *s2) //pa -> push(sa, sb);
{
	s1->head->next = s2->head;
	s2->head = NULL;
	s1->head = s1->head->next;
	s1->size += 1;
	s2->size -= 1;
	s1->head->index = s1->size;
	s1->op.p += 1;
}
