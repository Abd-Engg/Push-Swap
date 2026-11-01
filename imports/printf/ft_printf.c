/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:15:17 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/05 14:43:11 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

static int	handler(int fd, char format, va_list args)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr(fd, va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(fd, va_arg(args, char *)));
	else if (format == 'c')
		return (ft_putchar(fd, (char)va_arg(args, int)));
	else if (format == '%')
		return (ft_putchar(fd, '%'));
	else if (format == 'x' || format == 'X')
		return (ft_puthexa(fd, format,
				(unsigned long)va_arg(args, unsigned int)));
	else if (format == 'p')
		return (ft_putptr(fd, (unsigned long)va_arg(args, void *)));
	else if (format == 'u')
		return (ft_putunsigned(fd, va_arg(args, unsigned int)));
	else if (format == 'f')
		return (ft_putfloat(fd, (float)va_arg(args, double)));
	return (-1);
}

static int	check(int fd, const char *s, va_list args)
{
	int	ans;
	int	counter;
	int	i;

	ans = 0;
	i = 0;
	while (s[i])
	{
		if (s[i + 1] && s[i] == '%')
		{
			i++;
			counter = handler(fd, s[i], args);
		}
		else
			ans += ft_putchar(fd, s[i]);
		i++;
		if (counter == -1)
			return (-1);
		ans += counter;
	}
	return (ans);
}

int	ft_printf(int fd, const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	check(fd, s, args);
	va_end(args);
	return (count);
}
