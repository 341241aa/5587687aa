#include "copy.h"

void process_create(const char *srcfile, const char *destfile, int pronum, int blocksize)
{
    int i;
    for(i = 0; i < pronum; i++)
    {
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork fail");
            exit(EXIT_FAILURE);
        }
        if(pid == 0)
        {
            //子进程
            int offset = i * blocksize;
            char off_str[20], blk_str[20];
            bzero(off_str, sizeof(off_str));
            bzero(blk_str, sizeof(blk_str));
            sprintf(off_str, "%d", offset);
            sprintf(blk_str, "%d", blocksize);
            printf("子进程%d，offset=%d\n", getpid(), offset);

            execl("./COPY", "COPY", srcfile, destfile, off_str, blk_str, NULL);
            perror("execl error");
            exit(EXIT_FAILURE);
        }
    }
}
