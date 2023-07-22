/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epaksoy <epaksoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 20:04:11 by epaksoy           #+#    #+#             */
/*   Updated: 2023/07/22 14:51:38 by epaksoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(int a);
int	ft_puthex(int i, char c);
int	ft_point(unsigned long a);
int	ft_putnbr_u(unsigned int a);
int	ft_putstr(char *s);
int	ft_putchar(int c);
int	ft_check(const char *str, int i);
int	ft_formater(va_list *args, char c);
int	ft_printf(const char *str, ...);

#endif