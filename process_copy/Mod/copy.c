#include "copy.h"

int copy_segment(const char *src, const char *dest, int offset, int blocksize)
{
    int srcfd = open(src, O_RDONLY);
    if(srcfd <0){ perror("open src");return -1; }

    int destfd = open(dest, O_WRONLY|O_CREAT,0664);
    if(destfd <0){ perror("open dest");close(srcfd);return -1; }

    lseek(srcfd, offset, SEEK_SET);
    lseek(destfd, offset, SEEK_SET);

    char buf[4096];
    bzero(buf,sizeof(buf));
    int total = blocksize;
    int n;
    while(total > 0)
    {
        int rlen = (total > sizeof(buf)) ? sizeof(buf):total;
        n = read(srcfd, buf, rlen);
        if(n <= 0) break;
        write(destfd, buf, n);
        total -= n;
    }

    close(srcfd);
    close(destfd);
    return 0;
}

int main(int argc,char **argv)
{
    if(argc !=5)
    {
        printf("COPY usage: COPY srcfile destfile offset blocksize\n");
        exit(EXIT_FAILURE);
    }
    int offset = atoi(argv[3]);
    int blocksize = atoi(argv[4]);
    copy_segment(argv[1], argv[2], offset, blocksize);
    return 0;
}
