/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmalkaw <abmalkaw@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:53:34 by abmalkaw          #+#    #+#             */
/*   Updated: 2026/11/17 15:53:39 by abmalkaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/libft.h"
#include "../../header_files/pushswap.h"

t_parsing	init_r(void)
{
	t_parsing	ret;

	ret.data = NULL;
	ret.error = 0;
	ret.size = 0;
	ret.str = adaptive;
	ret.is_bench = 0;
	return (ret);
}

char	**split_argv(char **s, int *size)
{
	char	*joined;
	char	**splitted;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	joined = NULL;
	splitted = NULL;
	while (counter < *size)
		joined = ft_strjoin(joined, s[counter++]);
	splitted = ft_split(joined, ' ');
	free(joined);
	if (!splitted)
		return (NULL);
	while (splitted[i])
		i++;
	*size = i;
	return (splitted);
}

void	free_s(char **s)
{
	int	counter;

	counter = 0;
	if (!s)
		return ;
	while (s[counter])
		free(s[counter++]);
	free(s);
}

t_parsing	parsing_input(char **s, int size)
{
	t_parsing	return_value;
	int			counter;
	char		**splitted;

	counter = 0;
	splitted = split_argv(s, &size);
	return_value = init_r();
	if (!splitted)
		return (return_value);
	if (!check(splitted, size))
	{
		return_value.error = 1;
		return (free_s(splitted), return_value);
	}
	while (counter < size && isflag(s[counter]))
	{
		if (is_bench(s[counter]))
			return_value.is_bench = 1;
		else if (set_str(s[counter]) != NONE)
			return_value.str = add_str(splitted, counter);
		counter++;
	}
	return_value.size = size - counter;
	return_value.data = add_data(splitted, counter, &return_value);
	return_value.error |= isdup(return_value.data, return_value.size);
	free_s(splitted);
	return (return_value);
}
