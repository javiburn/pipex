/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:58:23 by jsarabia          #+#    #+#             */
/*   Updated: 2023/03/08 12:30:32 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	n;

	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	n = 0;
	while (s[n] != '\0' && s)
		write(fd, &s[n++], 1);
	return (n);
}
