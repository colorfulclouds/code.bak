/*************************************************************************
	> File Name: dup.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 20时25分09秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc , char *argv[])
{
    close(0);
    
    int fd = open(argv[1] , O_RDONLY);

    int newfd;
    newfd= dup(fd);
printf("new fd:%d\n", newfd);
    char buff[20];
    fgets(buff , 20 , stdin);

    printf("%s\n", buff);

    close(fd);

    return 0;

}
