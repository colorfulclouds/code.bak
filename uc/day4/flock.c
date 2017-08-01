/*************************************************************************
	> File Name: flock.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月10日 星期一 14时59分32秒
 ************************************************************************/

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char *argv[])
{
    int fd = open(argv[1] , O_RDWR);

    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    struct flcok pos;
    pos.l_type = F_WRLCK;
    pos.l_wherce = SEEK_SET;
    pos.l_start = 19;
    pos.l_len = 17;

    if( fcntl(fd , F_GETLK , &pos) == -1)
    {
        perror("get lock");
        close(fd);
        return 1;
    }

    if( pos.l_type == F_UNLOCK)
    {
        puts("not have lock");
    }
    else
    {
        puts("cannot add lock ");
        printf("pid:%d\n", pos.l_pid);
        printf("lock type:%d", pos.l_type);
    }
    


    return 0;
}
