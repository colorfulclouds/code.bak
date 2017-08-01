/*************************************************************************
	> File Name: getttytime.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 09时11分31秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
int main(int argc , char *argv[])
{
    struct stat one;
    stat(argv[1] , &one);
    time_t t;
    t = one.st_mtime;
    puts(ctime(&t));

    return 0;
}
