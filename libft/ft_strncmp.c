/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:21:41 by jsarabia          #+#    #+#             */
/*   Updated: 2023/01/25 18:17:46 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{	
	size_t	i;

	i = 0;
	if (num == 0)
		return (0);
	while ((i < num) && str1[i] == str2[i] && str1[i] && str2[i])
			i++;
	if (str1[i] != str2[i] && (i < num))
		return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	return (0);
}
