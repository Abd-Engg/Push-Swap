/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:26:05 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/17 11:26:06 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/ft_printf.h"
#include "../header_files/pushswap.h"

void	ss(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "ss\n");
	swap(sa);
	swap(sb);
	sa->op.ss++;
}

void	rr(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "rr\n");
	rot(sa);
	rot(sb);
	sa->op.rot_both++;
}

void	rrr(t_stack *sa, t_stack *sb)
{
	ft_printf(1, "rrr\n");
	revrot(sa);
	revrot(sb);
	sa->op.revrot_both++;
}
