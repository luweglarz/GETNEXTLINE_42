/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:17:29 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/24 16:41:03 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char			*swap_tmp(char *tmp, char *buff)
{
	char	*swap;

	swap = ft_strjoin(tmp, buff);
	free(tmp);
	tmp = ft_strdup(swap);
	free(swap);
	
	return (tmp);
}


int				read_line(char **tmp, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		read_size;
	char	save;

	while ((read_size = read(fd, buff, BUFFER_SIZE)))
	{	
		if (read_size == -1)
			return (-1);
		buff[read_size] = '\0';
		*tmp = swap_tmp(*tmp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*tmp;
	char			save;
	int				ret;
	int				line_n;

	ret = read_line(&tmp, fd);
	line_n = ft_strlenc(tmp, '\n');
	if (tmp)
	{
		if (ret != 0)
			*line = ft_substr(tmp, 0, line_n);
		else
			*line = ft_strdup(tmp);
	}
	return (ret);
}
