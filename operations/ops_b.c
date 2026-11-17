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

#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

void	sb(t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("sb");
	ft_lstadd_back(operations, node);
	swap(sb);
	sb->op.s++;
}

void	pb(t_stack *sb, t_stack *sa, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("pb");
	ft_lstadd_back(operations, node);
	push(sb, sa);
	sb->op.p += 1;
}

void	rb(t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("rb");
	ft_lstadd_back(operations, node);
	rot(sb);
	sb->op.rot++;
}

void	rrb(t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("rrb");
	ft_lstadd_back(operations, node);
	revrot(sb);
	sb->op.revrot++;
}
