/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:47:27 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/16 13:51:30 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct s_data
{
	char	*infile;
	char	*first_command;
	char	**f_input;
	char	*second_command;
	char	**s_input;
	char	*outfile;
}			t_data;

typedef struct s_pipe
{
	int	*fd_aux;
	int	*fd;
	int	id_aux;
	int	id;
	int	id2;
	int	o_fd;
}		t_pipe;

void	free_matrix(char **str);
t_data	create_arrays(t_data data, char **argv);
t_pipe	exec_aux(t_data data, t_pipe f_prog, char **env);
t_pipe	exec_command_one(t_data data, t_pipe f_prog, char **env);
t_pipe	exec_command_two(t_data data, t_pipe f_prog, char **env);

#endif
