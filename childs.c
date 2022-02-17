/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 03:15:20 by rigel             #+#    #+#             */
/*   Updated: 2022/02/17 21:44:45 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_cmd(char *path, char *cmd)
{
	char	*tmp;
	char	*command;

	tmp = ft_strjoin(path, "/");
	command = ft_strjoin(tmp, cmd);
	free(tmp);
	return (command);
}

void	child_process1(t_pipex pipex, char **argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**mycmdargs;

	mycmdargs = ft_split(argv[2], ' ');
	printf("pipi");
	i = 0;
	dup2(pipex.fdin, STDIN_FILENO);
	dup2(pipex.tube[1], STDOUT_FILENO);
	close(pipex.tube[0]);
	close(pipex.fdin);
	while (pipex.mypaths[i])
	{
		cmd = get_cmd(pipex.mypaths[i], mycmdargs[0]);
		execve(cmd, mycmdargs, envp);
		i++;
	}
}

void	child_process2(t_pipex pipex, char **argv, char **envp)
{
	int		i;
	char	*cmd;
	char	**mycmdargs;

	mycmdargs = ft_split(argv[3], ' ');
	i = 0;
	waitpid(pipex.pid1, NULL, 0);
	dup2(pipex.tube[0], STDIN_FILENO);
	dup2(pipex.fdout, STDOUT_FILENO);
	close(pipex.tube[1]);
	close(pipex.fdout);
	while (pipex.mypaths[i])
	{
		cmd = get_cmd(pipex.mypaths[i], mycmdargs[0]);
		execve(cmd, mycmdargs, envp);
		i++;
	}
}