/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparedes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 07:55:50 by mparedes          #+#    #+#             */
/*   Updated: 2023/03/24 07:55:53 by mparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

/*void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}*/

/*void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}*/

/*void	ft_putnbr_u(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	else
		ft_putchar(n + '0');
}*/

/*void	ft_puthex(unsigned int n, char *base)
{
	if (n > 15)
	{
		ft_puthex(n / 16, base);
		ft_puthex(n % 16, base);
	}
	else
		ft_putchar(base[n]);
}*/

/*void	ft_putstr_p(void *p)
{
	ft_putstr("0x");
	ft_puthex((unsigned long)p, "0123456789abcdef");
}*/

/*void	ft_putnbr_space(int n)
{
	if (n >= 0)
		ft_putchar(' ');
	ft_putnbr(n);
}*/

void	print_argument(char format, va_list ap)
{
	int d;
	char c; 
	//char *s;
	//void *p;
	//unsigned int u;

	if (format == ' ')
	{
		d = va_arg(ap, int);
		ft_putnbr_space(d);
	}
	else if (format == 'd')
	{
		d = va_arg(ap, int);
		ft_putnbr(d);
	}
	else if (format == 'c')
	{
		c = (char)va_arg(ap, int);
		ft_putchar(c);
	}
	else
		print_argument_ext(format, ap);
}

void	print_argument_ext(char format, va_list ap)
{
	char *s;
	void *p;
	unsigned int u;

	if (format == 's')
	{
		s = va_arg(ap, char *);
		ft_putstr(s);
	}
	else if (format == 'p')
	{
		p = va_arg(ap, void *);
		ft_putstr_p(p);
	}
	else if (format == 'u')
	{
		u = va_arg(ap, unsigned int);
		ft_putnbr_u(u);
	}
	else
		print_argument_hex(format, ap);
}

void	print_argument_hex(char format, va_list ap)
{
	unsigned int u;

	if (format == 'x' || format == 'X')
	{
		u = va_arg(ap, unsigned int);
		ft_puthex(u, format == 'x' ? "0123456789abcdef" : "0123456789ABCDEF");
	}
	else if (format == '%')
		ft_putchar('%');
}

void	ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_argument(*format, ap);
		}
		else
			ft_putchar(*format);
		format++;
	}
	va_end(ap);
}
