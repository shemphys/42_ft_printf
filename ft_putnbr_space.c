
#include "ft_printf.h"

void	ft_putnbr_space(int n)
{
	if (n >= 0)
		ft_putchar(' ');
	ft_putnbr(n);
}