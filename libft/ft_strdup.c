/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:50:48 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/25 14:23:03 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		n;
	int		len;

	n = 0;
	len = ft_strlen((char *)s);
	ptr = (char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (n < len)
	{
		ptr[n] = (char)s[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
