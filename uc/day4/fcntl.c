/*************************************************************************
	> File Name: fcntl.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月10日 星期一 14时36分55秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc , char *argv[])
{
    int fd = open(argv[1] , O_RDONLY);
    if(fd == -1)
    {
        perror("error");
        return 1;
    }
    
    struct flock pos;
    pos.l_type = F_RDLCK;
    pos.l_whence = SEEK_SET;
    pos.l_start = 19;
    pos.l_len = 17;
    pos.l_pid = -1;

    if( fcntl(fd , F_SETLK , &pos) == -1)
    {
        perror("fcntl");
        close(fd);
        return 2;
    }

    puts("lock success");
    sleep(10);
    pos.l_type = F_UNLCK;
    if( fcntl(fd , F_SETLK , &pos) == -1 )
    {
        close(fd);
        perror("unlock");
        return 3;
    }

    puts("ssss");
    close(fd);
    return 0;
}
