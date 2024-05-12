/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 01:15:16 by asayad            #+#    #+#             */
/*   Updated: 2023/12/20 13:24:40 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifiers(va_list p, char *str, int *cnt)
{
	if (*str && *str == 'c')
		ft_putchar(va_arg(p, int), cnt);
	if (*str && *str == 's')
		ft_putstr(va_arg(p, char *), cnt);
	if (*str && *str == 'p')
	{
		ft_putstr("0x", cnt);
		ft_ptnbb(va_arg(p, unsigned long long), "0123456789abcdef", *str, cnt);
	}
	if (*str && (*str == 'd' || *str == 'i'))
		ft_ptnbb(va_arg(p, int), "0123456789", *str, cnt);
	if (*str && *str == 'u')
		ft_ptnbb(va_arg(p, unsigned int), "0123456789", *str, cnt);
	if (*str && (*str == 'x' || *str == 'X'))
		ft_ptnbb(va_arg(p, unsigned int), "0123456789abcdef", *str, cnt);
	if (*str && *str == '%')
		ft_putchar('%', cnt);
	return (*(cnt));
}

int	ft_printf(const char *str, ...)
{
	va_list	first;
	int		count;

	if (write(1, "", 0) == -1)
		return (va_end (first), -1);
	va_start(first, str);
	count = 0;
	while (*str)
	{
		while (*str && *str != '%')
		{
			ft_putchar(*str, &count);
			str++;
		}
		if (*str == '%')
		{
			str++;
			format_specifiers(first, (char *)str, &count);
			str++;
		}
	}
	return (va_end (first), count);
}
