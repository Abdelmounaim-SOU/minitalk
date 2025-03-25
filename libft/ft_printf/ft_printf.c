/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:22:48 by asou              #+#    #+#             */
/*   Updated: 2024/12/11 16:15:18 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_parse(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
	{
		count += ft_putstr("0x");
		return (count + ft_putnbr_pointer(va_arg(ap, unsigned long)));
	}
	if (c == 'd' || c == 'i')
		return (ft_putnbr_decimal(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_putnbr_hex1(va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_putnbr_hex2(va_arg(ap, unsigned int)));
	return (ft_putchar(c));
}

static int	ft_printf_internal(const char *s, va_list ap, int count)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			count += ft_parse(s[i], ap);
		}
		else if (s[i] == '%' && s[i + 1] == '\0')
			return (count);
		else
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			(count)++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	ap;

	if (write(1, "", 0) == -1)
		return (-1);
	count = 0;
	va_start(ap, s);
	count = ft_printf_internal(s, ap, count);
	va_end(ap);
	return (count);
}
