/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 10:44:57 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/08 10:44:59 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header_files/ft_printf.h"

int	ft_putptr(int fd, unsigned long n)
{
	if (!n)
		return (ft_putstr(fd, "(nil)"));
	return (ft_putstr(fd, "0x") + ft_puthexa(fd, 'x', n));
}
