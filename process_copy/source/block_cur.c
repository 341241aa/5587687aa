#include "copy.h"

int block_cur(const char *srcfile, int pronum)
{
    int fd = open(srcfile, O_RDONLY);
    off_t filesize = lseek(fd, 0, SEEK_END);
    close(fd);
    printf("源文件总大小：%ld bytes\n", filesize);

    // blocksize = filesize / pronum +1
    int blocksize = filesize / pronum + 1;
    return blocksize;
}

