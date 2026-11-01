/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nalrjoub <nalrjoub@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 16:18:02 by nalrjoub          #+#    #+#             */
/*   Updated: 2026/10/03 12:33:06 by nalrjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(int fd, const char *s, ...);
int	ft_putchar(int fd, char c);
int	ft_putnbr(int fd, int nb);
int	ft_putunsigned(int fd, unsigned int n);
int	ft_putstr(int fd, char *s);
int	ft_puthexa(int fd, char c, unsigned long n);
int	ft_putptr(int fd, unsigned long n);
int	ft_putfloat(int fd, float nb);

#endif
