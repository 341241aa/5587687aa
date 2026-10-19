#include "copy.h"

void process_wait(void)
{
    pid_t zpid;
    while((zpid = wait(NULL)) > 0)
    {
        printf("父进程回收子进程 pid=%d\n", zpid);
    }
}
