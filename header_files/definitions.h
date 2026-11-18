/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   definitions.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 09:47:03 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/18 09:47:04 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINITIONS_H 
# define DEFINITIONS_H
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum e_strategy
{
	simple = 1,
	medium = 2,
	complex = 3,
	adaptive = 4,
	NONE = -1
}	t_strategy;

typedef struct s_parsing
{
	t_strategy	str;
	int			*data;
	int			size;
	int			error;
	int			is_bench;
}	t_parsing;

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_ops
{
	int	p;
	int	s;
	int	ss;
	int	rot;
	int	revrot;
	int	rot_both;
	int	revrot_both;
}					t_ops;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	t_ops			op;
	size_t			size;
}				t_stack;

#endif
