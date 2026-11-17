/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:52:10 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/11/17 15:52:14 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_files/definitions.h"
#include "header_files/pushswap.h"
#include "header_files/ft_printf.h"
#include "header_files/libft.h"

void	free_stack(t_stack *s)
{
	t_node	*cur;
	t_node	*tmp;

	cur = s->head;
	while (cur)
	{
		tmp = cur;
		cur = cur->prev;
		free(tmp);
	}
	free(s);
}

void	free_all(t_stack *a, t_stack *b, int *arr)
{
	free_stack(a);
	free_stack(b);
	free(arr);
}

void	selector(t_parsing _input, t_stack *a, t_stack *b, t_list **head)
{
	double	dis;
	int		flag;

	flag = 0;
	dis = disorder(a, a->size);
	if (_input.str == adaptive)
	{
		_input.str = _disorder(a);
		flag = 1;
	}
	if (_input.str == complex && dis)
		complex_sort(a, b, head);
	else if (_input.str == medium && dis)
		medium_sort(a, b, head);
	else if (_input.str == simple && dis)
		simple_sort(a, b, head);
	if (flag)
		_input.str = adaptive;
	while (*head)
	{
		ft_printf(1, "%s\n", (char *)(*head)->content);
		(*head) = (*head)->next;
	}
	if (_input.is_bench)
		print_benchmark(a, b, dis, _input);
}

void	push_swap(t_parsing _input, t_list **lst)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	t_list	*tmp;

	tmp = *lst;
	i = _input.size - 1;
	a = init_stack();
	b = init_stack();
	if (_input.error)
	{
		ft_printf(2, "Error\n");
		free_all(a, b, _input.data);
		return ;
	}
	while (i >= 0)
		add_new_node(a, _input.data[i--]);
	merge_sort(_input.data, 0, _input.size - 1);
	binary_search(a, _input.data);
	selector(_input, a, b, &tmp);
	free_all(a, b, _input.data);
}

int	main(int argc, char **argv)
{
	t_parsing	_input;
	t_list		*head;

	head = NULL;
	_input = parsing_input(argv + 1, argc - 1);
	push_swap(_input, &head);
	ft_lstclear(&head);
	return (0);
}
