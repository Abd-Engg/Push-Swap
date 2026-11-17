/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:52:42 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/11/17 15:52:44 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/pushswap.h"

int	pos(t_stack *s, int target)
{
	t_node	*curr;
	int		counter;

	curr = s->head;
	counter = 0;
	while (curr)
	{
		if (curr->content == target)
			return (counter);
		curr = curr->prev;
		counter++;
	}
	return (-1);
}

void	rotate(t_stack *s, int index, t_list **operations)
{
	int	tmp;

	if (index <= 0)
		return ;
	if (index == 1)
		sa(s, operations);
	else if (index <= (int)s->size / 2)
	{
		while (index--)
			ra(s, operations);
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
			rra(s, operations);
	}
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b, t_list **operations)
{
	int	index;
	int	target;

	target = 0;
	while (stack_a->size)
	{
		index = pos(stack_a, target);
		rotate(stack_a, index, operations);
		pb(stack_b, stack_a, operations);
		target++;
	}
	while (stack_b->size)
		pa(stack_a, stack_b, operations);
}
