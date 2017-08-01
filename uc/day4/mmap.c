/*************************************************************************
	> File Name: mmap.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月10日 星期一 17时03分16秒
 ************************************************************************/

#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
    umask(0);
    int fd = open("mmap" , O_RDWR | O_CREAT , 0644);
    if(fd == -1)
    {
        perror("open");
        return 1;
    }

    ftruncate(fd , 1024);//resize file to 1024B=1K
    char *p = mmap(0,1024,PROT_WRITE | PROT_READ,MAP_SHARED, fd , SEEK_SET);
    if(p == (void *)-1)
    {
        perror("mmap");
        close(fd);
        return 1;
    }
    int cnt=0;
    for(;;)
    {
        if(p[0] != '\0')
        {
            printf("%s", p);
            memset(p , 0 , strlen(p));
            cnt = 0;
        }
        else
        {
            if(++cnt == 20)
                break;
        }
        usleep(1000*500);//0.5s
    }
    munmap(p , 1024);
    close(fd);

    return 0;
}
