# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

////////////////////////////////////////////
int	ft_string(char const *str)
{
if (!str)
	return (write (1, "(null)", ft_strlen("(null)")));
return (write (1, str, ft_strlen(str)));
}

///////////////////////////////////////////

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

///////////////////////////////////////////

int	ft_pointer(void *p)//yo lo hab'ia llamado ft_pointer en la principal
{
	size_t p_num;

	p_num = (size_t)p;
	return (write(1, "0x", 2) + ft_base(p_num, "0123456789abcdef"));
}

///////////////////////////////////////////

int	ft_menu(va_list x, const char *c)
{
//d i x X u -> me los cargo porque puedo agruparlos por base
	if (*c == 'c')
		return (ft_putchar(va_arg(x, int)));
	else if (*c == '%')
		return (ft_putchar('%'));
	else if (*c == 's')
		return (ft_string(va_arg(x, char const *)));/////NOT DONE YET	
	else if (*c == 'p')
		return (ft_pointer(va_arg(x, void *)));////NOT DONE YET
	else
		return (ft_number(va_arg(x, int), *c));/////To be done yet
	return (0);
}

int	ft_printf(char const *s, ...)
{
	va_list x;//x contiene la lista de argumentos
	int		count;

	va_start (x, s);//s es la cabeza de esa lista de argumentos
	count = 0;
	while (*s)
	{
		if (*s == '%')
			count += ft_menu(x, ++s);
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end (x);
	return (count);
}