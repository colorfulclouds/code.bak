/*************************************************************************
	> File Name: fdopen.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 20时50分52秒
 ************************************************************************/

#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int fd;
    fd = open(argv[1] , O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    FILE *fp;
    fp = fdopen(fd , "r");
    if(fp == NULL)
    {
        close(fd);
        perror("open 2");
        return 2;
    }

    char buff[20];
    fgets(buff , 20 , fp);

    printf("%s\n", buff);
    fclose(fp);
    close(fd);

    return 0;
}
