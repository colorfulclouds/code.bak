/*************************************************************************
	> File Name: dup2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 21时35分07秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc , char *argv[])
{
    int fd;
    fd = open(argv[1] , O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    int ff = dup2(fd , 0);
 close(fd);
    printf("ff:%d\n", ff);

    char buff[20];
    fgets(buff , 20 , stdin);
    printf("%s", buff);

   // close(fd);

    return 0;
}
