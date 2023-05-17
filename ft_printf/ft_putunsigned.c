/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:44:14 by jsarabia          #+#    #+#             */
/*   Updated: 2023/03/08 15:17:18 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	unsigned int	u;
	int				count;

	u = n;
	count = 0;
	if (n < 0)
		u = 4294967295 + n;
	while (u > 9)
	{
		count = ft_putnbr_fd(u / 10, 1);
		u = u % 10;
	}
	if (u >= 0 && u <= 9)
	{
		u = u + '0';
		write(1, &u, 1);
	}
	return (count + 1);
}
