/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:44:14 by jsarabia          #+#    #+#             */
/*   Updated: 2023/03/27 15:01:20 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned long n)
{
	int	count;

	count = 1;
	while (n > 15)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_putaddress(unsigned long p)
{
	char			*elements;
	char			*toprint;
	unsigned long	operation;
	int				n;

	n = ft_count(p);
	elements = ft_callocprintf(17, sizeof(char));
	ft_strlcpyprintf(elements, "0123456789abcdef", 17);
	write(1, "0x", 2);
	toprint = ft_callocprintf(n + 1, sizeof(char));
	while (n > 0)
	{
		operation = p % 16;
		toprint[n - 1] = elements[operation];
		p /= 16;
		n--;
	}
	while (toprint[n] != '\0')
		write(1, &toprint[n++], 1);
	free(elements);
	free(toprint);
	return (n + 2);
}
