/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:55:40 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/27 12:46:18 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *)big);
	if ((!big && len == 0)
		|| ft_strlen((char *)big) < ft_strlen((char *)little))
		return (NULL);
	if (len > (size_t)ft_strlen((char *)big))
		len = ft_strlen((char *)big);
	while (big[i + j] != '\0' && little[j] != '\0' && i + j < len)
	{
		if (big[i + j] == little[j] && i + j < len)
			j++;
		else if (big[i + j] != little[j] && little[j] != '\0')
		{
			j = 0;
			i++;
		}
	}
	if ((little[j] == '\0' && little[j - 1] == big[i + j - 1]) || i + j < len)
		return ((char *)big + i);
	return (NULL);
}
