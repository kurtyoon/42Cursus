#include "get_next_line.h"

char *get_next_line(int fd) {

    int i = 0;
    int rd = 0;
    char c;
    char *buf = malloc(10000);

    while ((rd = read(fd, &c, 1)) > 0) {
        buf[i++] = c;
        if (c == '\n')
            break ;
    }
    if ((!buf[i - 1] && !rd) || rd == -1) {
        free(buf);
        return (NULL);
    }
    buf[i] = '\0';
    return (buf);
}
