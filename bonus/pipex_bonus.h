/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 09:29:29 by ayblin            #+#    #+#             */
/*   Updated: 2022/02/23 17:49:44 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

typedef struct s_pipex
{
	int		pid1;
	int		pid2;
	int		tube[2];
	int		fdin;
	int		fdout;
	char	*paths;
	char	**mypaths;
	char	*path_from_envp;
	char	*cmd;
	char	**mycmdargs;
}t_pipex;


#endif