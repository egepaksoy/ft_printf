/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:04:20 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/17 20:26:40 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	long	n;
	char	c;

	n = 0;
	while (s[n])
	{
		c = s[n];
		write(1, &c, 1);
		n++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int i)
{
	if (i == -2147483648)
		write(1, "-2147483648", 11);
	else if (i < 0)
	{
		ft_putchar('-');
		ft_putnbr(i * -1);
	}
	else if (i > 10)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + 48);
	}
	else
		ft_putchar(i + 48);
}

void	ft_putnbr_u(int i)
{
	if (i < 0)
		ft_putnbr_u(i * -1);
	else if (i > 10)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + 48);
	}
	else
		ft_putchar(i + 48);
}

void	ft_puthex(int i, char c)
{
	if (i >= 16)
		ft_puthex(i / 16, c);
	if (c == 'X')
		ft_putchar("0123456789ABCDEF"[i % 16]);
	if (c == 'x')
		ft_putchar("0123456789abcdef"[i % 16]);
}
