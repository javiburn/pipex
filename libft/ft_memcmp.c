/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:29:40 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/25 13:32:47 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	res = 0;
	if (n == 0)
		return (0);
	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	while (i < n)
	{
		if (c[i] == d[i])
			i++;
		else
		{
			res = c[i] - d[i];
			return (res);
		}
	}
	return (0);
}
