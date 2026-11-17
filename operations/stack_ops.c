/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:26:10 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/17 11:26:12 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/pushswap.h"

void	push(t_stack *s1, t_stack *s2) //pa -> push(stackA, stackB);
{
	if (!s2->head)
		return ;
	add_new_node(s1, s2->head->content);
	del_node(s2);
}

void	swap(t_stack *s1) //sa -> swap(**stackA)
{
	int	tmp;

	if (!s1 || s1->size < 2)
		return ;
	tmp = s1->head->content;
	s1->head->content = s1->head->prev->content;
	s1->head->prev->content = tmp;
}

void	rot(t_stack *s1)
{
	t_node	*head;
	t_node	*tail;
	t_node	*prev;

	head = s1->head;
	tail = s1->tail;
	prev = head->prev;
	if (!prev)
		return ;
	head->next = tail;
	head->prev = NULL;
	prev->next = NULL;
	tail->prev = head;
	s1->tail = head;
	s1->head = prev;
}

void	revrot(t_stack *s1)
{
	t_node	*head;
	t_node	*tail;
	t_node	*next;

	head = s1->head;
	tail = s1->tail;
	next = tail->next;
	if (!next)
		return ;
	head->next = tail;
	next->prev = NULL;
	tail->next = NULL;
	tail->prev = head;
	s1->head = tail;
	s1->tail = next;
}
