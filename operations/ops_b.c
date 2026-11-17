/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:25:57 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/17 11:25:59 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/pushswap.h"

void	sb(t_stack *sb)
{
	ft_printf(1, "sb\n");
	swap(sb);
	sb->op.s++;
}

void	pb(t_stack *sb, t_stack *sa)
{
	ft_printf(1, "pb\n");
	push(sb, sa);
	sb->op.p += 1;
}

void	rb(t_stack *sb)
{
	ft_printf(1, "rb\n");
	rot(sb);
	sb->op.rot++;
}

void	rrb(t_stack *sb)
{
	ft_printf(1, "rrb\n");
	revrot(sb);
	sb->op.revrot++;
}
