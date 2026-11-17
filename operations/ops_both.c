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

#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

void	ss(t_stack *sa, t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("ss");
	ft_lstadd_back(operations, node);
	swap(sa);
	swap(sb);
	sa->op.ss++;
}

void	rr(t_stack *sa, t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("rr");
	ft_lstadd_back(operations, node);
	rot(sa);
	rot(sb);
	sa->op.rot_both++;
}

void	rrr(t_stack *sa, t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("rrr");
	ft_lstadd_back(operations, node);
	revrot(sa);
	revrot(sb);
	sa->op.revrot_both++;
}
