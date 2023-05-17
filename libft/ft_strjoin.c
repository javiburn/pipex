/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:26:55 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/27 12:53:03 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		n;
	int		i;

	if (s1[0] == '\0' && s2[0] == '\0')
	{
		p = (char *)malloc(1 * sizeof(char));
		p[0] = '\0';
		return (p);
	}
	n = ft_strlen((char *)s1);
	i = ft_strlen((char *)s2);
	p = (char *)malloc((n + i) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	if (s1[0] != '\0')
		ft_strlcpy(p, s1, n + 1);
	if (s2[0] != '\0')
		ft_strlcpy(p + n, s2, i + 1);
	return (p);
}
