/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:34:49 by lweglarz          #+#    #+#             */
/*   Updated: 2020/08/10 12:57:47 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[i] && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}