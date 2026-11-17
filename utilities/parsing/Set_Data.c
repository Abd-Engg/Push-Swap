/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Set_Data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:52:59 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/11/17 15:53:01 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/pushswap.h"
#include "../../header_files/libft.h"

t_strategy	set_str(char *s)
{
	if (ft_strcmp(s, "--simple") == 0)
		return (simple);
	if (ft_strcmp(s, "--medium") == 0)
		return (medium);
	if (ft_strcmp(s, "--complex") == 0)
		return (complex);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (adaptive);
	return (NONE);
}

t_strategy	add_str(char **s, int start)
{
	t_strategy	ret;

	ret = adaptive;
	if (isflag(s[start]))
	{
		ret = set_str(s[start]);
		start++;
	}
	return (ret);
}

int	*add_data(char **s, int start, t_parsing *return_value)
{
	int		*ret;
	int		size;
	long	num;
	int		counter;

	size = return_value->size;
	ret = malloc(sizeof(long) * size);
	if (!ret)
		return (NULL);
	counter = 0;
	while (counter < size)
	{
		num = ft_atoi(s[start + counter]);
		if (num > T_MAX || num < T_MIN)
			return_value->error = 1;
		ret[counter] = num;
		counter++;
	}
	return (ret);
}
