/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:34:38 by asou              #+#    #+#             */
/*   Updated: 2024/11/03 15:56:30 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_len(int n)
{
	size_t	count;

	count = (n <= 0);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	fill_result(char *result, long num, size_t len)
{
	size_t	i;

	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	result[len] = '\0';
	i = len - 1;
	if (num == 0)
		result[0] = '0';
	while (num > 0)
	{
		result[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	long	num;
	size_t	len;
	char	*result;

	num = n;
	len = num_len(num);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	fill_result(result, num, len);
	return (result);
}
