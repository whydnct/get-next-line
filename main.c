#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(int argc, char** argv)
{
    int fd;
    int lines;
    int i;

    (void)argc;
    lines = atoi(argv[2]);
    i = 0;
    fd = open(argv[1], O_RDONLY);
    while (i < lines)
    {
        printf("%s", get_next_line(fd));
        i++;
    }
}