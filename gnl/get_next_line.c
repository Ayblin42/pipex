/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblin <ayblin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:23:09 by ayblin            #+#    #+#             */
/*   Updated: 2021/12/17 19:48:17 by ayblin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_ptr(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*s_str = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!s_str)
		s_str = ft_strdup("");
	if (read_file(fd, &s_str, &buffer, &line) < 1 && *line == '\0')
	{
		free_ptr(line);
		return (NULL);
	}
	return (line);
}

int	read_file(int fd, char **s_str, char **buffer, char **line)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (!ft_strchr(*s_str, '\n') && bytes_read)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[bytes_read] = '\0';
		tmp = *s_str;
		*s_str = ft_strjoin(*s_str, *buffer);
		free_ptr(tmp);
	}
	free_ptr(*buffer);
	get_line(line, s_str);
	return (bytes_read);
}

void	get_line(char **line, char **s_str)
{
	int		jump;
	char	*temp;

	jump = 0;
	temp = *s_str;
	while ((*s_str)[jump] != '\n' && (*s_str)[jump] != '\0')
		jump++;
	if (ft_strchr(*s_str, '\n'))
	{
		*line = ft_substr(*s_str, 0, jump + 1);
		*s_str = ft_strdup(*s_str + jump + 1);
	}
	else
	{
		*line = ft_strdup(temp);
		*s_str = NULL;
	}
	free_ptr(temp);
}
