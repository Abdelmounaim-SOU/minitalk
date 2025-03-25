/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:03:46 by asou              #+#    #+#             */
/*   Updated: 2024/11/03 12:48:30 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	l;
	char	c;

	l = n;
	if (fd < 0)
		return ;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = -1 * l;
	}
	if (l > 9)
		ft_putnbr_fd(l / 10, fd);
	c = l % 10 + '0';
	ft_putchar_fd(c, fd);
}
