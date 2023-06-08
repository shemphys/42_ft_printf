
#include "ft_printf.h"

int	ft_base(size_t n, char *base)
{
	size_t	len;

	len = 1;
	if (n >= (size_t)ft_strlen(base))
	{
		len += ft_base(n / ft_strlen(base), base);
		ft_putchar(base[n % ft_strlen(base)]);
	}
	else
		ft_putchar(base[n]);
	return (len);
}

//may error at if n bigger than int -> size_t n??
int ft_number(int n, char menu)
{
	char	*base_x;//hexadecimal minusculas
	char	*base_X;//hexadecimal mayusculas
	char	*base_diu;//decimales

	base_x = "0123456789abcdef";
	base_X = "0123456789ABCDEF";
	base_diu = "0123456789";
	if (menu == 'd' || menu == 'i')
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11));
		else if (n < 0)
			return (ft_putchar('-') + ft_base(n * -1, base_diu));
	}
	else if (menu == 'u')
		return (ft_base((size_t)n, base_diu));
	else if (menu == 'x')
		return (ft_base((size_t)n, base_x));
	else if (menu == 'X')
		return (ft_base((size_t)n, base_X));
	return (1);
}

int	ft_pointer(void *p)
{
	size_t p_num;

	p_num = (size_t)p;
	return (write(1, "0x", 2) + ft_base(p_num, "0123456789abcdef"));
}


