/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 17:57:40 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/05 14:44:03 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

int	ft_putstr(int fd, char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr(fd, "(null)"));
	while (s[i])
	{
		ft_putchar(fd, s[i]);
		i++;
	}
	return (i);
}
