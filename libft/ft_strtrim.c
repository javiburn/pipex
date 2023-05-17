/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:12:52 by jsarabia          #+#    #+#             */
/*   Updated: 2023/02/02 17:50:04 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ch_check(char c, char const *set)
{
	int	n;

	n = 0;
	while (set[n] != '\0')
	{
		if (c == (char)set[n])
			return (1);
		else
			n++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f;
	char	*p;

	i = 0;
	if (!s1)
		return (NULL);
	f = (int)ft_strlen(s1) - 1;
	while (s1[i] && ch_check((char)s1[i], set))
		i++;
	if (ft_strlen(s1) > 0)
	{
		while (f >= 0 && ch_check((char)s1[f], set))
		f--;
	}
	if (f < 0)
	{
		p = ft_calloc(1, 1);
		return (p);
	}
	p = (char *)malloc((f - i) * sizeof(char) + 2);
	if (!p)
		return (NULL);
	ft_strlcpy(p, s1 + i, (f - i + 2));
	return (p);
}
