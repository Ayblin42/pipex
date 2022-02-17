/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:39:50 by rigel             #+#    #+#             */
/*   Updated: 2022/02/17 21:47:47 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	printf("sperme");
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.fdin = open(argv[1], O_RDONLY);
	pipex.fdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.fdin < 0 || pipex.fdout < 0)
		return (1);
	pipex.path_from_envp = find_path(envp);
	printf("prout");
	pipex.mypaths = ft_split(pipex.path_from_envp, ':');
	pipe(pipex.tube);
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		return (1);
	if (pipex.pid1 == 0)
		child_process1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		return (1);
	if (pipex.pid2 == 0)
		child_process2(pipex, argv, envp);
	printf("caca");
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}
