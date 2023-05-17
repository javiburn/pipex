/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:47:46 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/26 12:16:42 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*nodo;

	nodo = (t_list *)malloc(sizeof(*nodo));
	if (!nodo)
		return (NULL);
	nodo->content = content;
	nodo->next = NULL;
	return (nodo);
}
/*
int main()
{
	char	*content;
	char	*nodo;

	content = ft_lstnew(content);
	printf("%s", nodo);
	return (0);
}
*/
