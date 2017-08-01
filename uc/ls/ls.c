/*************************************************************************
	> File Name: ls.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月07日 星期五 15时39分27秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc , char *argv[])
{
    if(argc == 1)
    {
        puts("lack paras");
        return 1;
    }

    struct dirent *dir_s;
    DIR *dir_d;

    dir_d = opendir(argv[1]);
    if(dir_d == NULL)
    {
        perror("open dir");
        return 2;
    }

    while((dir_s = readdir(dir_d)) != NULL)
    {
        puts(dir_s->d_name);
    }

    return 0;
}
