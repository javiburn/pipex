/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:40:34 by jsarabia          #+#    #+#             */
/*   Updated: 2023/02/01 16:22:31 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		len += 1;
		n = n * (-1);
	}
	while (n > 9)
	{
		if (n % 10 >= 0 && n % 10 <= 9)
			len += 1;
		n = n / 10;
	}
	len += 1;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		in;

	in = n;
	len = ft_len(n);
	s = (char *)ft_calloc((len + 1), sizeof(char));
	if (!s)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	if (n < 0)
		n = n * (-1);
	while (len - 1 >= 0)
	{
		if (n % 10 >= 0 && n % 10 <= 9)
			s[(len--) - 1] = n % 10 + '0';
		n = n / 10;
	}
	if (in < 0)
		s[0] = '-';
	return (s);
}
