#include "get_next_line.h"
#include <stdio.h>

int get_next_line(int fd, char **line)
{
    char        buff[BUFFER_SIZE + 1];
    int         ret;
    int         pos;

    pos = ft_strlenc(buff, '\n');
    ret = read(fd, buff, BUFFER_SIZE);
    *line = ft_substr(buff, 0, pos);

    return (ret);
}