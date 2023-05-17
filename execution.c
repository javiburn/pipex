/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:12:11 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/16 17:51:56 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

int	number_y(char **array)
{
	int	y;

	y = 0;
	if (ft_strncmp(array[0], "ps", 2) == 0)
		return (y);
	while (array[y] != '\0')
		y++;
	return (y);
}

t_pipe	exec_aux(t_data data, t_pipe prog, char **env)
{
	char	**arr;

	arr = ft_calloc(3, sizeof(char *));
	arr[0] = ft_calloc(9, sizeof(char));
	ft_strlcpy(arr[0], "/bin/cat", 9);
	arr[1] = ft_substr(data.infile, 0, ft_strlen(data.infile));
	prog.fd_aux = ft_calloc(3, sizeof(int));
	pipe(prog.fd_aux);
	prog.id_aux = fork();
	if (prog.id_aux == 0)
	{
		dup2(prog.fd_aux[1], STDOUT_FILENO);
		close(prog.fd_aux[0]);
		close(prog.fd_aux[1]);
		execve("/bin/cat", arr, env);
		free_matrix(arr);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	waitpid(prog.id_aux, NULL, 0);
	return (prog);
}

t_pipe	exec_command_one(t_data data, t_pipe f_prog, char **env)
{
	char	**arr;
	int		y;

	y = number_y(data.f_input);
	arr = ft_calloc(y + 2, sizeof(char *));
	while (--y > 0)
		arr[y] = ft_substr(data.f_input[y], 0, ft_strlen(data.f_input[y]));
	arr[0] = ft_substr(data.first_command, 0, ft_strlen(data.first_command));
	f_prog.fd = ft_calloc(3, sizeof(int));
	dup2(f_prog.fd_aux[0], STDIN_FILENO);
	close(f_prog.fd_aux[0]);
	close(f_prog.fd_aux[1]);
	pipe(f_prog.fd);
	f_prog.id = fork();
	if (f_prog.id == 0)
	{
		dup2(f_prog.fd[1], STDOUT_FILENO);
		close(f_prog.fd[0]);
		close(f_prog.fd[1]);
		execve(data.first_command, arr, env);
		perror("execve one");
		exit(EXIT_FAILURE);
	}
	waitpid(f_prog.id, NULL, 0);
	return (f_prog);
}

t_pipe	exec_command_two(t_data data, t_pipe f_prog, char **env)
{
	char	**arr;
	int		y;

	y = number_y(data.s_input);
	arr = ft_calloc(y + 1, sizeof(char *));
	while (--y > 0)
		arr[y] = ft_substr(data.s_input[y], 0, ft_strlen(data.s_input[y]));
	arr[0] = ft_substr(data.second_command, 0, ft_strlen(data.second_command));
	dup2(f_prog.fd[0], STDIN_FILENO);
	close(f_prog.fd[0]);
	close(f_prog.fd[1]);
	f_prog.o_fd = open(data.outfile, O_WRONLY | O_CREAT, 0644);
	dup2(f_prog.o_fd, 1);
	execve(data.second_command, arr, env);
	free_matrix(arr);
	perror("execve two");
	exit(EXIT_FAILURE);
	close(f_prog.o_fd);
	waitpid(f_prog.id2, NULL, 0);
	return (f_prog);
}
