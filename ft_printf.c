/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 20:02:13 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/24 12:35:33 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_check(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == '%'));
}

int	ft_formater(va_list *args, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_putnbr_u(va_arg((*args), long)));
	else if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == 'x' || c == 'X')
		return (ft_hex(va_arg((*args), int), c));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else if (c == 's')
		return (ft_putstr(va_arg((*args), char *)));
	else
		return (ft_putchar('%'));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	va_start(args, str);
	while (str[++i])
	{
		if (ft_check(str, i))
			ret += ft_formater(&args, str[++i]);
		else
			ret += ft_putchar(str[i]);
	}
	va_end(args);
	return (ret);
}
