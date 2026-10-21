#include "../header_files/pushswap.h"


void	push(t_stack *s1, t_stack *s2) //pa -> push(stackA, stackB);
{
	if (!s2->head)
		return ;
	add_new_node(s1,s2->head->content);
	del_node(s2);
	s1->op.p += 1;
}

// void	push(t_stack *s1, t_stack *s2) //pa -> push(stackA, stackB);
// {
// 	s1->head->next = s2->head;
// 	s2->head = NULL;
// 	s1->head = s1->head->next;
// 	s1->size += 1;
// 	s2->size -= 1;
// 	s1->op.p += 1;
// }

void	swap(t_stack *s1) //sa -> swap(**stackA)
{
	if (!s1 || s1->size < 2)
		return;
	
	int tmp = s1->head->content;
	s1->head->content = s1->head->prev->content;
	s1->head->prev->content = tmp; 
	s1->op.s++;
}

// void	swap(t_stack *s1) //sa -> swap(**stackA)
// {
// 	int contentfirst = (s1)->head->content;
// 	int contentsecond = (s1)->head->prev->content;
// 	del_node(s1);
// 	del_node(s1);
// 	add_new_node(s1,contentfirst);
// 	add_new_node(s1,contentsecond);
// 	(s1)->op.s += 1;
// }

// void	swap(t_stack **s1) //sa -> swap(**stackA)
// {
// 	t_node	*prev;
// 	t_node	*pprev;
// 	t_node	*head;

// 	head = (*s1)->head;
// 	prev = head->prev;
// 	if (!prev)
// 		return ;
// 	pprev = prev->prev;
// 	if (pprev)
// 		pprev->next = (*s1)->head;
// 	else
// 	 (*s1)->tail = head;
// 	prev->prev = head;
// 	head->prev = pprev;
// 	head->next = prev;
// 	prev->next = NULL;
// 	(*s1)->head = prev;
// }

void	rot(t_stack **s1)
{
	t_node	*head;
	t_node	*tail;
	t_node	*prev;

	head = (*s1)->head;
	tail = (*s1)->tail;
	prev = head->prev;
	if (!prev)
		return ;
	head->next = tail;
	head->prev = NULL;
	prev->next = NULL;
	tail->prev = head;
	(*s1)->tail = head;
	(*s1)->head = prev;
}

void	revrot(t_stack **s1)
{
	t_node	*head;
	t_node	*tail;
	t_node	*next;

	head = (*s1)->head;
	tail = (*s1)->tail;
	next = tail->next;
	if (!next)
		return ;
	head->next = tail;
	next->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	(*s1)->head = tail;
	(*s1)->tail = next;
}
