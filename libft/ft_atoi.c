/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:05:59 by jsarabia          #+#    #+#             */
/*   Updated: 2023/04/12 13:46:04 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	n;
	int	sign;
	int	res;

	n = 0;
	sign = 1;
	res = 0;
	while (nptr[n] == ' ' || nptr[n] == '\n' || nptr[n] == '\t'
		|| nptr[n] == '\v' || nptr[n] == '\f' || nptr[n] == '\r')
		n++;
	if (nptr[n] == '-' || nptr[n] == '+')
	{
		if (nptr[n] == '-')
			sign = -1;
		n += 1;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		res = res * 10;
		res = res + (nptr[n] - '0');
		n++;
		if (nptr[n] == '\0')
			return (res * sign);
	}
	return (0);
}
