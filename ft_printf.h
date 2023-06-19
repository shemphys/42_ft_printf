/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparedes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:38:50 by mparedes          #+#    #+#             */
/*   Updated: 2023/06/19 16:38:51 by mparedes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_strlen(const char *s);
int	ft_base(size_t n, char *base);
int	ft_number(int n, char menu);
int	ft_pointer(void *p);
int	ft_menu(va_list x, const char *c);
int	ft_printf(char const *s, ...);

#endif
