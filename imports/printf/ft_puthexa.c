/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 11:23:03 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/05 14:43:32 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

int	ft_puthexa(int fd, char c, unsigned long n)
{
	char	*sc;
	char	*s;
	int		count;

	count = 0;
	s = "0123456789abcdef";
	sc = "0123456789ABCDEF";
	if (c == 'p' && !n)
		return (ft_putstr(fd, "(nil)"));
	if (n > 15)
	{
		if (c == 'x')
			count += ft_puthexa(fd, c, n / 16);
		else
			count += ft_puthexa(fd, c, n / 16);
	}
	if (c == 'x')
		count += ft_putchar(fd, s[n % 16]);
	else if (c == 'X')
		count += ft_putchar(fd, sc[n % 16]);
	return (count);
}
