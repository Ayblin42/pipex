/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:10:06 by ayblin            #+#    #+#             */
/*   Updated: 2022/02/23 17:58:41 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.fdin = open(argv[1], O_RDONLY);
	pipex.fdout = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if (pipex.fdin < 0 || pipex.fdout < 0)
		return (ft_msg("failed to open infile or outfile"));
	pipex.path_from_envp = find_path(envp);
	pipex.mypaths = ft_split(pipex.path_from_envp, ':');
	pipe(pipex.tube);
	while()
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
}
