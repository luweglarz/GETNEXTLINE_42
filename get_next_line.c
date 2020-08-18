#include "get_next_line.h"
#include <stdio.h>



int get_next_line(int fd, char **line)
{
    static char *tmp;
    char        *save;
    char        buff[BUFFER_SIZE + 1];
    int         read_size;

    while (read_size = read(fd, buff, BUFFER_SIZE) > 0);
    {
        buff[read_size] = '\0';
        if (tmp = NULL)
            tmp = ft_strdup("");
        tmp = ft_strjoin(tmp, buff);
    }
    return (read_size);
}