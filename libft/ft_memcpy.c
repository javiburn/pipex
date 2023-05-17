/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:37:28 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/25 18:01:41 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	i = 0;
	if (!src && !dest)
		return (dest);
	s = (char *)src;
	d = (char *)dest;
	while (i < n)
	{
		*d++ = *s++;
		i++;
	}
	return (dest);
}
