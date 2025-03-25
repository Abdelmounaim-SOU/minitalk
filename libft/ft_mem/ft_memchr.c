/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:55:14 by asou              #+#    #+#             */
/*   Updated: 2024/11/15 00:14:27 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc;
	unsigned char	*ptr;

	i = 0;
	uc = (unsigned char) c;
	ptr = (unsigned char *) s;
	while (i < n)
	{
		if (ptr[i] == uc)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}
