/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:22:29 by ayblin            #+#    #+#             */
/*   Updated: 2022/02/23 15:09:23 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->mycmdargs[i])
	{
		free(pipex->mycmdargs[i]);
		i++;
	}
	free(pipex->mycmdargs);
	free(pipex->cmd);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->fdin);
	close(pipex->fdout);
	while (pipex->mypaths[i])
	{
		free(pipex->mypaths[i]);
		i++;
	}
	free(pipex->mypaths);
}
