/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:51:37 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/11/17 16:05:13 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stddef.h>
# include <stdlib.h>
# include "definitions.h"
# define T_MAX 2147483647
# define T_MIN -2147483648

void		del_node(t_stack *s);
t_node		*add_new_node(t_stack *s, int content);
t_stack		*init_stack(void);
void		push(t_stack *s1, t_stack *s2);
void		swap(t_stack *s1);
void		rot(t_stack *s1);
void		revrot(t_stack *s1);
void		ra(t_stack *sa, t_list **operations);
void		pa(t_stack *sa, t_stack *sb, t_list **operations);
void		sa(t_stack *sa, t_list **operations);
void		sb(t_stack *sb, t_list **operations);
void		pb(t_stack *sb, t_stack *sa, t_list **operations);
void		rb(t_stack *sb, t_list **operations);
void		rra(t_stack *sa, t_list **operations);
void		rrb(t_stack *sb, t_list **operations);
void		ss(t_stack *sa, t_stack *sb, t_list **operations);
void		rr(t_stack *sa, t_stack *sb, t_list **operations);
void		rrr(t_stack *sa, t_stack *sb, t_list **operations);
void		sort(int *arr, int l, int mid, int r);
int			*fill_arr(int *arr, int size, int idx);
void		binary_search(t_stack *s, int *arr);
void		merge_sort(int *arr, int l, int r);
void		complex_sort(t_stack *stack_a, t_stack *stack_b,
				t_list **operations);
int			count(int n);
double		disorder(t_stack *s, int size);
void		simple_sort(t_stack *stack_a, t_stack *stack_b,
				t_list **operations);
int			pos(t_stack *s, int target);
void		medium_sort(t_stack *stack_a, t_stack *stack_b,
				t_list **operations);
t_parsing	parsing_input(char **s, int size);
int			isdup(int *data, int size);
int			*add_data(char **s, int start, t_parsing *return_value);
t_strategy	add_str(char **s, int start);
int			check(char **s, int size);
t_parsing	init_r(void);
t_strategy	set_str(char *s);
int			is_number(char *s);
int			isflag(char *s);
int			is_bench(char *s);
t_strategy	_disorder(t_stack *a);
void		print_benchmark(t_stack *a, t_stack *b, float dis,
				t_parsing _input);
char		**split_argv(char **s, int *size);
void		free_s(char **s);
int			check_error(t_parsing return_value);
int			total_operations(t_stack *a, t_stack *b);
void		free_stack(t_stack *s);
void		free_all(t_stack *a, t_stack *b, int *arr);

#endif
