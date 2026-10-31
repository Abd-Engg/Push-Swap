/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 14:09:14 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/09/17 14:09:25 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/libft.h"

void	free_strings(char *s1)
{
	if (s1)
		free(s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	while (i + j < ft_strlen(s1) + ft_strlen(s2))
	{
		if (s1 && s1[i])
		{
			str[i + j] = s1[i];
			i++;
		}
		else
		{
			str[i + j] = s2[j];
			j++;
		}
	}
	free_strings(s1);
	str[i + j] = ' ';
	str[i + j + 1] = '\0';
	return (str);
}
