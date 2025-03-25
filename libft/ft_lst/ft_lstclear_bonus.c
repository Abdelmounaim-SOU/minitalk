/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asou <asou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 01:03:00 by asou              #+#    #+#             */
/*   Updated: 2024/11/04 01:03:01 by asou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*next_node;

	if (!lst || !del || !*lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next_node = temp->next;
		ft_lstdelone(temp, del);
		temp = next_node;
	}
	*lst = NULL;
}
