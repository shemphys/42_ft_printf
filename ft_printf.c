#include "printf.h"

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

int	ft_string(char const *str)
{
if (!str)
	return (write (1, "(null)", ft_strlen("(null)")));
return (write (1, str, ft_strlen(str)));
}

int	ft_menu(va_list x, const char *c)
{
	if (*c == 'c')
		return (ft_putchar(va_arg(x, int)));
	else if (*c == '%')
		return (ft_putchar('%'));
	else if (*c == 's')
		return (ft_string(va_arg(x, char const *)));	
	else if (*c == 'p')
		return (ft_pointer(va_arg(x, void *)));
	else
		return (ft_number(va_arg(x, int), *c));
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