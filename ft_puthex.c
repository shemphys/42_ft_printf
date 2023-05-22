
#include "ft_printf.h"

void	ft_puthex(unsigned int n, char *base)
{
	if (n > 15)
	{
		ft_puthex(n / 16, base);
		ft_puthex(n % 16, base);
	}
	else
		ft_putchar(base[n]);
}