/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:34:31 by jsarabia          #+#    #+#             */
/*   Updated: 2023/02/02 17:36:16 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (len > (size_t)ft_strlen((char *)s))
		len = (size_t)ft_strlen((char *)s);
	if (!s)
		return (NULL);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	if (start >= (unsigned int)ft_strlen((char *)s))
	{
		*str = '\0';
		return (str);
	}
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
