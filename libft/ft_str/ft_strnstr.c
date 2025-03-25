/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:55:21 by asou              #+#    #+#             */
/*   Updated: 2024/11/16 10:14:51 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (i < len && haystack[i])
	{
		while (needle[j] && (i + j) < len && needle[j] == haystack[i + j])
			j++;
		if (needle[j] == '\0')
			return ((char *) &haystack[i]);
		j = 0;
		i++;
	}
	return (NULL);
}
