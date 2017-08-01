/*************************************************************************
	> File Name: read_file.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月07日 星期五 21时33分21秒
 ************************************************************************/

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc , char *argv[])
{
    int fd;
    fd = open(argv[1] , O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    char buff[20];
    read(fd , buff , sizeof(buff));
    puts(buff);


    close(fd);

    return 0;
}
