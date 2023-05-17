/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:49:32 by jsarabia          #+#    #+#             */
/*   Updated: 2023/03/27 15:00:20 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *s, ...);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putaddress(unsigned long p);
void	*ft_callocprintf(size_t n, size_t size);
size_t	ft_strlcpyprintf(char *dest, const char *src, size_t n);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunsigned(unsigned int n);
int		ft_puthexamin(unsigned int p);
int		ft_puthexamay(unsigned int p);

#endif
