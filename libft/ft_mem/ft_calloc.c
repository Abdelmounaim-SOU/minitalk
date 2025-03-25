/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:55:05 by asou              #+#    #+#             */
/*   Updated: 2024/11/03 13:04:28 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	void			*result;

	if (size != 0 && count > (SIZE_MAX / size))
		return (NULL);
	total_size = count * size;
	result = malloc(total_size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, total_size);
	return (result);
}
