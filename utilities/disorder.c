/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:26:42 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/17 11:26:44 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/pushswap.h"

double	disorder(t_stack *s, int size)
{
	long	total_pairs;
	long	mistakes;
	t_node	*curr;
	t_node	*c;

	if (!size)
		return (0);
	c = s->head;
	curr = s->head;
	total_pairs = ((size - 1) * (size)) / 2.0;
	if (!total_pairs)
		return (0);
	mistakes = 0;
	while (c)
	{
		curr = c->prev;
		while (curr)
		{
			if (c->content > curr->content)
				mistakes++;
			curr = curr->prev;
		}
		c = c->prev;
	}
	return ((double)mistakes / (double)total_pairs);
}

t_strategy	_disorder(t_stack *a)
{
	double	dis;

	dis = disorder(a, a->size);
	if (dis < 0.2 || a->size <= 5)
		return (simple);
	else if (dis < 0.5)
		return (medium);
	else
		return (complex);
}
