/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarabia <jsarabia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:39:29 by jsarabia          #+#    #+#             */
/*   Updated: 2023/05/24 13:54:50 by jsarabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

char	*check_param(char *argv)
{
	char	*str;
	char	**aux;

	aux = ft_split(argv, ' ');
	if (!aux)
	{
		str = ft_substr(argv, 0, ft_strlen(argv));
		return (str);
	}
	str = ft_substr(aux[0], 0, ft_strlen(aux[0]));
	free_matrix(aux);
	return (str);
}

char	*find_command(char *argv, char **paths)
{
	char	*str;
	char	*temp;
	char	*aux;

	argv = check_param(argv);
	if (access(argv, F_OK) == 0)
		return (argv);
	while (*paths != '\0')
	{
		aux = ft_strjoin(*paths, "/");
		temp = ft_strjoin(aux, argv);
		if (access(temp, F_OK) == 0)
		{
			str = ft_substr(temp, 0, ft_strlen(temp));
			free(temp);
			free(aux);
			free(argv);
			return (str);
		}
		paths++;
		free(temp);
		free(aux);
	}
	free(argv);
	return (NULL);
}

char	**find_path(char **env)
{
	char	*path_line;
	char	**paths;
	int		cont;

	cont = 0;
	while (env[cont] != '\0' && ft_strncmp("PATH=", env[cont], 5) != 0)
		cont++;
	path_line = ft_calloc(ft_strlen(env[cont]) - 4, sizeof(char));
	if (!path_line)
	{
		perror("malloc");
		exit (EXIT_FAILURE);
	}
	ft_strlcpy(path_line, env[cont] + 5, ft_strlen(env[cont]) - 4);
	paths = ft_split(path_line, ':');
	if (!paths)
	{
		perror("split");
		exit (EXIT_FAILURE);
	}
	free(path_line);
	return (paths);
}

t_data	checks(int argc, char **argv, char **env, t_data data)
{
	char	**paths;

	if (argc != 5 || access(data.infile, F_OK != 0))
	{
		perror("arguments");
		exit(EXIT_FAILURE);
	}
	paths = find_path(env);
	if (!paths)
		exit(EXIT_FAILURE);
	data.first_command = find_command(argv[2], paths);
	if (!data.first_command)
	{
		perror("command");
		exit(EXIT_FAILURE);
	}
	data.second_command = find_command(argv[3], paths);
	if (!data.second_command)
	{
		perror("command");
		exit(EXIT_FAILURE);
	}
	free_matrix(paths);
	return (data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	t_pipe	prog;

	if (env[0] == NULL)
	{
		perror("environment");
		exit(EXIT_FAILURE);
	}
	data.infile = argv[1];
	data.outfile = argv[4];
	unlink(data.outfile);
	prog.o_fd = open(data.outfile, O_WRONLY | O_CREAT, 0644);
	if (prog.o_fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	data = checks(argc, argv, env, data);
	data = create_arrays(data, argv);
	prog = exec_aux(data, prog, env);
	prog = exec_command_one(data, prog, env);
	prog = exec_command_two(data, prog, env);
	close(prog.fd_aux[0]);
	close(prog.fd_aux[1]);
	exit(0);
}
