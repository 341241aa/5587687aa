#include "copy.h"

int main(int argc , char ** argv)
{
    int pronum = 1;
    const char *srcfile;
    const char *destfile;

    //两种传参方式
    if(argc == 3)
    {
        srcfile = argv[1];
        destfile = argv[2];
        pronum = 1;
    }
    else if(argc == 4)
    {
        srcfile = argv[1];
        destfile = argv[2];
        pronum = atoi(argv[3]);
    }
    else
    {
        printf("usage: %s srcfile destfile [pronum]\npronum default=1\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    int ret = check_pram(argc, srcfile, pronum);
    if(ret != 0)
    {
        printf("参数校验失败！\n");
        exit(EXIT_FAILURE);
    }

    int blocksize = block_cur(srcfile, pronum);
    printf("文件分块大小 blocksize = %d\n", blocksize);

    process_create(srcfile, destfile, pronum, blocksize);

    process_wait();

    printf("====全部拷贝任务完成====\n");
    return 0;
}
