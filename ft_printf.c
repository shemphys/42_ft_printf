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

int	ft_printf(char const *str, ...)
{
	va_list archivo;
	int		x;

	x = 0;
	
	va_start(archivo, str);

	while (!str)
	{
		if (str == '%' && !(str++ == 'c' || str++ == 's' || str++ == 'p' 
		|| str++ == 'i' || str++ == 'd' || str++ == 'u' || str++ == 'x' 
		|| str++ == 'X' || str++ == '%'))
			ft_error()
			ft_menu(str++);
		str++;
	}
	return (1);
}
