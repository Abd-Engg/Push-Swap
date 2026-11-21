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

#include "../header_files/pushswap.h"
#include "../header_files/libft.h"

void	sa(t_stack *sa, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("sa");
	ft_lstadd_back(operations, node);
	swap(sa);
	sa->op.s++;
}

void	pa(t_stack *sa, t_stack *sb, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("pa");
	ft_lstadd_back(operations, node);
	push(sa, sb);
	sa->op.p += 1;
}

void	ra(t_stack *sa, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("ra");
	ft_lstadd_back(operations, node);
	rot(sa);
	sa->op.rot++;
}

void	rra(t_stack *sa, t_list **operations)
{
	t_list	*node;

	node = ft_lstnew("rra");
	ft_lstadd_back(operations, node);
	revrot(sa);
	sa->op.revrot++;
}
