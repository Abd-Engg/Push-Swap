/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:28:10 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/11/17 11:28:12 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

int	ft_putfloat(int fd, float nb)
{
	int	count;

	nb *= 100;
	count = ft_putnbr(fd, nb);
	nb *= 100;
	count += ft_putchar(fd, '.');
	count += ft_putnbr(fd, ((int)nb % 100) / 10);
	count += ft_putnbr(fd, ((int)nb % 100) % 10);
	return (count);
}
