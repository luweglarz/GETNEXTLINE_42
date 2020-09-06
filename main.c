#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int    main(int ac, char **av)
{
    int        i;
    int        fd1;
    int        fd2;
    int        ret1;
    int        ret2;
    char    *line1;
    char    *line2;
    i = 0;
    line1 = NULL;
    (void)ac;
    fd1 = open(av[1], O_RDONLY);
    fd2 = open(av[2], O_RDONLY);
    while ((ret1 = get_next_line(fd1, &line1)) > 0 && (ret2 = get_next_line(fd2, &line2)) > 0)
    {
        printf("file 1[%d][%d]=%s\n", ret1, i, line1);
        printf("file 2[%d][%d]=%s\n", ret2, i, line2);
        if (line1)
            free(line1);
        if (line2)
            free(line2);
        line2 = NULL;
        i++;
    }
    printf("[%d][%d]=%s\n", ret1, i, line1);
    close(fd1);
    // system("leaks a.out");
    return (0);
}