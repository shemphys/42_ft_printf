/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparedes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 06:25:26 by mparedes          #+#    #+#             */
/*   Updated: 2023/03/24 06:25:28 by mparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int n);
void		ft_putnbr_u(unsigned int n);
void		ft_puthex(unsigned int n, char *base);
void		ft_putstr_p(void *p);
void		ft_putnbr_space(int n);
void		ft_printf(const char *format, ...);
static void	print_argument(char format, va_list ap)
static void	print_argument_ext(char format, va_list ap)
static void	print_argument_hex(char format, va_list ap)


#endif
