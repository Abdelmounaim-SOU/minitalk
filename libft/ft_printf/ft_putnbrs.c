/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:45:25 by asou              #+#    #+#             */
/*   Updated: 2024/12/11 13:32:29 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_decimal(int n)
{
	long	l;
	int		count;

	count = 0;
	l = n;
	if (l < 0)
	{
		ft_putchar('-');
		count++;
		l = -l;
	}
	if (l > 9)
		count += ft_putnbr_decimal(l / 10);
	count += ft_putchar(l % 10 + '0');
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

int	ft_putnbr_hex1(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
		count += ft_putnbr_hex1(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putnbr_hex2(unsigned int n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	if (n > 15)
		count += ft_putnbr_hex2(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putnbr_pointer(unsigned long n)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
		count += ft_putnbr_pointer(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}
