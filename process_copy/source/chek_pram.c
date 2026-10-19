#include "copy.h"

int check_pram(int argc, const char *srcfile, int pronum)
{
 
    if(argc < 3)
    {
        printf("error\n");
        return -1;
    }
  
    int fd = open(srcfile, O_RDONLY);
    if(fd < 0)
    {
        perror("error\n");
        return -1;
    }
    close(fd);

    //进程数范围：1 <= pronum <100
    if(pronum < 1 || pronum >= 100)
    {
        printf("错误：进程数必须满足 1<=pronum<100\n");
        return -1;
    }
    return 0;
}
