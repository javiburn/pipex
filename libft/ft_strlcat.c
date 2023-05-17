/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:58:13 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/27 15:59:38 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	n;
	size_t	count;

	if (dest == 0 && destsize == 0)
		return (0);
	if (destsize < (size_t)ft_strlen(dest))
		return (destsize + (size_t)ft_strlen((char *)src));
	i = ft_strlen(dest);
	n = 0;
	count = ft_strlen(dest) + ft_strlen((char *)src);
	while ((i + 1 < destsize) && src[n] != '\0')
	{
		dest[i] = src[n];
		n++;
		i++;
	}
	dest[i] = '\0';
	return (count);
}
