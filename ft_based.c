/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_based.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparedes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:25 by mparedes          #+#    #+#             */
/*   Updated: 2023/06/19 16:33:31 by mparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_number(int n, char menu)
{
	char	*base_x;
	char	*base_bigx;
	char	*base_diu;

	base_x = "0123456789abcdef";
	base_bigx = "0123456789ABCDEF";
	base_diu = "0123456789";
	if (menu == 'd' || menu == 'i')
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11));
		else if (n < 0)
			return (ft_putchar('-') + ft_base(n * -1, base_diu));
		else
			return (ft_base(n, base_diu));
	}
	else if (menu == 'u')
		return (ft_base((unsigned int)n, base_diu));
	else if (menu == 'x')
		return (ft_base((unsigned int)n, base_x));
	else if (menu == 'X')
		return (ft_base((unsigned int)n, base_bigx));
	return (1);
}

int	ft_pointer(void *p)
{
	size_t	p_num;

	p_num = (size_t)p;
	return (write(1, "0x", 2) + ft_base(p_num, "0123456789abcdef"));
}
