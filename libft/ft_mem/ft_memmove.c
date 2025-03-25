/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:51:02 by asou              #+#    #+#             */
/*   Updated: 2024/11/15 00:15:44 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*ptr_dst;
	unsigned char		*ptr_src;

	if (dst == src)
		return (dst);
	ptr_dst = (unsigned char *) dst;
	ptr_src = (unsigned char *) src;
	if (ptr_src < ptr_dst)
	{
		ptr_dst += len;
		ptr_src += len;
		while (len--)
			*(--ptr_dst) = *(--ptr_src);
	}
	else
	{
		while (len--)
			*(ptr_dst++) = *(ptr_src++);
	}
	return (dst);
}
