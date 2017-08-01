/*************************************************************************
	> File Name: cp.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月07日 星期五 14时16分26秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFF 1024

void cp_data(char *argv_src , char *argv_des)
{
    void *buff;
    buff = malloc(MAX_BUFF);

    if( strcmp(argv_src , argv_des) == 0 )
        printf("same file cannot copy\n");
    else
    {
        int fd_src = open(argv_src , O_RDONLY);
        if(fd_src == -1)
        {
            perror("open src");
            return ;
        }
        int fd_des = open(argv_des , O_WRONLY);
        if(fd_des == -1)
        {
            perror("open des");
            return ;
        }

        int result;

        while( (result = read(fd_src , buff , MAX_BUFF) ) > 0)
        {
            write(fd_des , buff , result);
        }

        close(fd_src);
        close(fd_des);
    }
}

int main(int argc , char *argv[])
{
    if(argc <= 2)
    {
        puts("lack of paras");
        return 1;
    }
    else
    {
        if(access(argv[2] , F_OK) == 0)
        {
            char choice;
            int i=1;
            for(;i<argc ; i ++)
            {
                if(strcmp(argv[i], "-i") == 0)
                {
                    puts("cover it?");
                    scanf("%c", &choice);
                    if(choice == 'y')
                        cp_data(argv[1] , argv[2]);
                    else
                        return 0;
                }
            }
        }
        else
        {
            cp_data(argv[1] , argv[2]);
        }
        
    }

    return 0;
}
