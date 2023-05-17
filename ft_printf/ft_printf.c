/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:44:14 by jsarabia          #+#    #+#             */
/*   Updated: 2023/03/08 16:14:07 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft.h"

static int	ft_letter(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (c == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (c == 'p')
		return (ft_putaddress(va_arg(args, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (c == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (ft_puthexamin(va_arg(args, unsigned int)));
	else if (c == 'X')
		return (ft_puthexamay(va_arg(args, unsigned int)));
	else if (c == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	int		n;
	int		count;
	va_list	args;

	count = 0;
	va_start(args, s);
	n = 0;
	while (s[n] != '\0')
	{
		if (s[n] == '%')
		{
			count += ft_letter(s[n + 1], args);
			n += 2;
		}
		if (!s[n])
			break ;
		if (s[n] != '%')
		{
			write(1, &s[n], 1);
			n++;
			count++;
		}
		va_end(args);
	}
	return (count);
}
/*
int main()
{
	char	e[5] = "Hola";

	ft_printf(" %X \n", 9223372036854775807LL);
	printf(" %X ", 9223372036854775807LL);
	return (0);
}
*/
