/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:04:20 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/22 14:51:56 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	long	n;
	char	c;

	n = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[n])
	{
		c = s[n];
		write(1, &c, 1);
		n++;
	}
	return (n);
}

int	ft_putnbr(int a)
{
	int	ret;

	ret = 0;
	if (a == 0)
		return (write(1, "0", 1));
	if (a == -2147483648)
		return (write(1, "-2147483648", 11));
	if (a < 0)
	{
		ret += write(1, "-", 1);
		a *= -1;
	}
	if (a >= 10)
		ret += ft_putnbr(a / 10);
	ret += write(1, &"0123456789"[a % 10], 1);
	return (ret);
}

int	ft_putnbr_u(unsigned int a)
{
	int	ret;

	ret = 0;
	if (a >= 10)
		ret += ft_putnbr_u(a / 10);
	ret += write(1, &"0123456789"[a % 10], 1);
	return (ret);
}

int	ft_puthex(int i, char c)
{
	int	ret;

	ret = 0;
	if (i >= 16)
		ret += ft_puthex(i / 16, c);
	if (c == 'X')
		ret += write(1, &"0123456789ABCDEF"[i % 16], 1);
	if (c == 'x')
		ret += write(1, &"0123456789abcdef"[i % 16], 1);
	return (ret);
}

int	ft_point(unsigned long a)
{
	write(1, "0x", 2);
	return (2 + ft_puthex(a, 'x'));
}
