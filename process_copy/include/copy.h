#ifndef __COPY_H__
#define __COPY_H__

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

//函数声明
int check_pram(int argc, const char *srcfile, int pronum);
int block_cur(const char *srcfile, int pronum);
void process_create(const char *srcfile, const char *destfile, int pronum, int blocksize);
void process_wait(void);
int copy_segment(const char *src, const char *dest, int offset, int blocksize);

#endif
