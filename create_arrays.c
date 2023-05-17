/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:46:52 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/16 18:42:31 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

char	**create_input(char **str, char *argv)
{
	if (ft_strncmp("awk", argv, 3) == 0)
	{
		str = ft_calloc(3, sizeof(char *));
		str[0] = ft_calloc(4, sizeof(char));
		ft_strlcpy(str[0], "awk", 4);
		str[1] = ft_calloc(ft_strlen(argv) - 6, sizeof(char));
		str[1] = ft_strtrim(argv, "/usr/bin/awk ' ");
		return (str);
	}
	else
	{
		str = ft_calloc(2, sizeof(char *));
		str[0] = ft_calloc(ft_strlen(argv) + 1, sizeof(char));
		ft_strlcpy(str[0], argv, ft_strlen(argv) + 1);
	}
	return (str);
}

t_data	create_arrays(t_data data, char **argv)
{
	if (ft_strncmp("awk", argv[2], 3) != 0)
		data.f_input = ft_split(argv[2], ' ');
	else if (ft_strncmp("awk", argv[2], 3) == 0
		|| ft_strncmp("grep", argv[2], 4) == 0)
		data.f_input = create_input(data.f_input, argv[2]);
	if (!data.f_input)
		data.f_input = create_input(data.f_input, argv[2]);
	if (ft_strncmp("awk", argv[3], 3) != 0)
		data.s_input = ft_split(argv[3], ' ');
	else if (ft_strncmp("awk", argv[3], 3) == 0
		|| ft_strncmp("grep", argv[3], 4) == 0)
		data.s_input = create_input(data.s_input, argv[3]);
	if (!data.s_input)
		data.s_input = create_input(data.s_input, argv[3]);
	return (data);
}
