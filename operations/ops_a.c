/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 14:30:11 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/09 14:30:30 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/pushswap.h"

void	sa(t_stack *sa)
{
	ft_printf(1, "sa\n");
	swap(sa);
	sa->op.s++;
}

void	pa(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "pa\n");
	push(sa, sb);
	sa->op.p += 1;
}

void	ra(t_stack *sa)
{
	ft_printf(1, "ra\n");
	rot(sa);
	sa->op.rot++;
}

void	rra(t_stack *sa)
{
	ft_printf(1, "rra\n");
	revrot(sa);
	sa->op.revrot++;
}
