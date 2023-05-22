
#include "ft_printf.h"

void	ft_putstr_p(void *p)
{
	ft_putstr("0x");
	ft_puthex((unsigned long)p, "0123456789abcdef");
}