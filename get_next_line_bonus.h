/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolandgamos <rolandgamos@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:34:08 by rolandgamos       #+#    #+#             */
/*   Updated: 2020/09/08 11:48:22 by lweglarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
int		ft_strlenc(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
void	ft_bzero(void *s, size_t n);

#endif
