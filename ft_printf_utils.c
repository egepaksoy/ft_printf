/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:04:20 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/22 13:39:45 by epaksoy          ###   ########.fr       */
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

int	ft_putnbr(int i)
{
	int	ret;

	ret = 0;
	if (i == -2147483648)
		ret += write(1, "-2147483648", 11);
	else if (i < 0)
	{
		ret += write(1, "-", 1);
		ret += ft_putnbr(i * -1);
	}
	else if (i > 10)
	{
		ret += ft_putnbr(i / 10);
		ret += write(1, &"0123456789"[i % 10], 1);
	}
	else
		ret += write(1, &"0123456789"[i % 10], 1);
	return (ret);
}

int	ft_putnbr_u(unsigned int i)
{
	int	ret;

	ret = 0;
	if (i < 0)
		ret += ft_putnbr_u(i * -1);
	else if (i > 10)
	{
		ret += ft_putnbr(i / 10);
		ret += write(1, &"0123456789"[i % 10], 1);
	}
	else
		ret += write(1, &"0123456789"[i % 10], 1);
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

int	ft_point(int i)
{
	int	ret;

	ret = 0;
	ret += write(1, "0x", 2);
	ret += ft_puthex(i, 'x');
	return (ret);
}
