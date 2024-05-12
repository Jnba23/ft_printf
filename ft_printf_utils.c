/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asayad <asayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:00:00 by asayad            #+#    #+#             */
/*   Updated: 2023/12/20 12:38:24 by asayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *p)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*p += 6;
		return ;
	}
	(*p) += write(1, s, ft_strlen(s));
}

void	ft_putchar(char c, int *p)
{
	write(1, &c, 1);
	(*p)++;
}

void	ft_ptnbb(long long x, char *base, char c, int *p)
{
	size_t	bl;

	bl = ft_strlen(base);
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (c != 'p')
	{
		if (x < 0)
		{
			ft_putchar('-', p);
			x *= -1;
		}
	}
	if (x / bl != 0)
		ft_ptnbb(x / bl, base, c, p);
	ft_putchar(base[x % bl], p);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
