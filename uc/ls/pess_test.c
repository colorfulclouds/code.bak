/*************************************************************************
	> File Name: pess_test.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月08日 星期六 16时47分41秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc , char *argv[])
{
    int fd = open(argv[1] , O_WRONLY);
    if(fd == -1)
    {
        perror("open file");
        return 1;
    }

    char buff[20];
    read(fd , buff , 20);
    puts(buff);

    sleep(20);
puts("after sleep");
    int result;

    result = read(fd , buff , 20);

    printf("result:%d\n", result);

    if(result < 0 )
    {
        perror("open error");
        close(fd);
        return 2;
    }
    puts(buff);
    close(fd);

    return 0;
}
