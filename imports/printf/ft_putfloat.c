#include "../../header_files/ft_printf.h"

int	ft_putfloat(int fd, float nb)
{
	int	count;
	int	i;

	nb *= 100;
	count = ft_putnbr(fd, nb);
	i = 0;
	nb *= 100;
	count += ft_putchar(fd, '.');
	count += ft_putnbr(fd, ((int)nb % 100) / 10);
	count += ft_putnbr(fd, ((int)nb % 100) % 10);
	return (count);
}
