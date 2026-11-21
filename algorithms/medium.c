/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:52:32 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/11/17 15:52:33 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/pushswap.h"

int	chunk_size(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	stage_a(t_stack *stack_a, t_stack *stack_b, t_list **operations)
{
	int	chunk;
	int	start;
	int	counter;

	chunk = chunk_size(stack_a->size);
	start = 0;
	while (stack_a->size)
	{
		counter = 0;
		while (counter < chunk && stack_a->size)
		{
			if (stack_a->head->content >= start
				&& stack_a->head->content < start + chunk)
			{
				pb(stack_b, stack_a, operations);
				counter++;
			}
			else
				ra(stack_a, operations);
		}
		start += chunk;
	}
}

void	rotate_b(t_stack *s, int index, t_list **operations)
{
	int	tmp;

	if (index <= 0)
		return ;
	if (index <= (int)s->size / 2)
	{
		while (index--)
			rb(s, operations);
	}
	else
	{
		tmp = s->size - index;
		while (tmp--)
			rrb(s, operations);
	}
}

void	medium_sort(t_stack *stack_a, t_stack *stack_b, t_list **operations)
{
	int	target;

	stage_a(stack_a, stack_b, operations);
	target = stack_b->size - 1;
	while (stack_b->size)
	{
		rotate_b(stack_b, pos(stack_b, target), operations);
		pa(stack_a, stack_b, operations);
		target--;
	}
}
