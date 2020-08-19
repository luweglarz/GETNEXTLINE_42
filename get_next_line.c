/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:17:29 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/19 16:25:34 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*swap_tmp(char *tmp, int line_n)
{
	int		tmp_size;
	char	*swap;

	tmp_size = ft_strlenc(tmp, '\0');
	swap = ft_substr(tmp, line_n + 1, tmp_size);
	free(tmp);
	tmp = NULL;
	tmp = ft_strdup(swap);
	free(swap);
	swap = NULL;
	return (tmp);
}

int				read_line(char *tmp, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_size;

	while ((read_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[read_size] = '\0';
		if (tmp == NULL)
			tmp = ft_strdup("");
		if (read_size == -1)
			return (-1);
		tmp = ft_strjoin(tmp, buff);
		if (read_size == 1)
			return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*tmp;
	int				ret;
	int				line_n;

	ret = read_line(tmp, fd);
	line_n = ft_strlenc(tmp, '\n');
	if (ret == 1)
	{
		if (line_n == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_substr(tmp, 0, line_n);
			tmp = swap_tmp(tmp, line_n);
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (ret);
}
