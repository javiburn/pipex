/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:50:01 by jsarabia          #+#    #+#             */
/*   Updated: 2023/02/01 17:49:38 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	n;

	n = (int)ft_strlen((char *)str);
	if (c == '\0')
		return ((char *)str + n);
	while (n >= 0)
	{
		if (str[n] == (unsigned char)c)
			return ((char *)str + n);
		n--;
	}
	return (NULL);
}
