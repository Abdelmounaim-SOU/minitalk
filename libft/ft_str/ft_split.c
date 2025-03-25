/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:36:53 by asou              #+#    #+#             */
/*   Updated: 2024/11/03 11:29:42 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	is_new;

	i = 0;
	count = 0;
	is_new = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && is_new)
		{
			count++;
			is_new = 0;
		}
		if (s[i] == c)
			is_new = 1;
		i++;
	}
	return (count);
}

static int	free_splits(char **result, size_t index)
{
	while (index--)
		free(result[index]);
	free(result);
	return (0);
}

static int	fillstr(char **result, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			result[index] = ft_substr(s, i, j - i);
			if (!result[index])
				return (free_splits(result, index));
			index++;
			i = j;
		}
	}
	result[index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**result;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	result = (char **) malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	if (!fillstr(result, s, c))
		return (NULL);
	return (result);
}
