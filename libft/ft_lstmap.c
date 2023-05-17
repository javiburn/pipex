/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:08:28 by jsarabia          #+#    #+#             */
/*   Updated: 2023/02/06 13:59:07 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if (lst && f && del)
	{
		new = ft_lstnew(f(lst->content));
		start = new;
		lst = lst->next;
		if (!start)
			return (NULL);
		while (lst != NULL)
		{
			new->next = ft_lstnew(f(lst->content));
			new = new->next;
			lst = lst->next;
		}
		return (start);
	}
	return (NULL);
}
