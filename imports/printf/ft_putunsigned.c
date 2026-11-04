/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:10:43 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/05 14:44:22 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

int	ft_putunsigned(int fd, unsigned int n)
{
	char	c;
	int		counter;

	counter = 0;
	if (n >= 10)
		counter += ft_putunsigned(fd, n / 10);
	c = n % 10 + '0';
	counter += ft_putchar(fd, c);
	return (counter);
}
