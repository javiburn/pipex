/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:24:43 by jsarabia          #+#    #+#             */
/*   Updated: 2023/02/06 14:00:00 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*borrar;

	if (*lst && del)
	{
		while (*(lst) != NULL)
		{
			borrar = *lst;
			*lst = borrar->next;
			del(borrar->content);
			free(borrar);
		}
		lst = NULL;
	}
}
