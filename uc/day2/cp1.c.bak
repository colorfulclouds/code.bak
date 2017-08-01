/*************************************************************************
	> File Name: cp1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月04日 星期二 21时23分00秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 1000

void copy(int src_fd , int des_fd)
{
    char buf[BUFFER_SIZE];
    int result;

    while( (result = read(src_fd , buf , BUFFER_SIZE)) > 0)
    {
        write(des_fd , buf , result);
    }
}

int main(int argc , char *argv[])
{
    if(argc <= 2)
    {
        printf("lack of paras\n");
        exit(EXIT_FAILURE);
    }

    int src_fd;
    int des_fd;

    src_fd = open(argv[1] , O_RDONLY);
    if(src_fd == -1)
    {
        perror("open src");
        exit(EXIT_FAILURE);
    }

    des_fd = open(argv[2] , O_WRONLY);
    if(des_fd == -1)
    {
        close(src_fd);
        perror("open des");
        exit(EXIT_FAILURE);
    }

    copy(src_fd , des_fd);

    close(src_fd);
    close(des_fd);

    return 0;
}
