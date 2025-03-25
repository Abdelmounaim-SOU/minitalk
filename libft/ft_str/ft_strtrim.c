/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:02:23 by asou              #+#    #+#             */
/*   Updated: 2024/11/16 10:16:42 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*start;
	char const	*end;
	size_t		len;

	if (!s1 || !(s1 && set))
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = s1 + ft_strlen(s1);
	while (end > start && ft_strrchr(set, *(end - 1)))
		end--;
	len = end - start;
	return (ft_substr(start, 0, len));
}
