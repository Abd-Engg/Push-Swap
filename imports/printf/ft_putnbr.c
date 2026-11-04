/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 18:05:29 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/05 14:43:45 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

int	ft_putnbr(int fd, int nb)
{
	char	c;
	long	n;
	int		count;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count += ft_putchar(fd, '-');
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr(fd, n / 10);
	c = n % 10 + '0';
	count += ft_putchar(fd, c);
	return (count);
}
