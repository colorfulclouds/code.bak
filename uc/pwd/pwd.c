/*************************************************************************
	> File Name: pwd.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 15时29分17秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int get_inode(char *file)
{
    struct stat one;
    stat(file , &one);

    return one.st_ino;
}

int main()
{
    DIR *dir;
    struct dirent *dd;

    ino_t my_inode;
    my_inode = get_inode(".");

    while(get_inode("..") != my_inode)
    {
        chdir("..");
        dir = opendir(".");

        while( (dd = readdir(dir)) != NULL)
        {
            if(dd->d_ino == my_inode)
            {
                puts(dd->d_name);
                closedir(dir);
                break;
            }
        }

        my_inode = get_inode(".");
    }


    return 0;
}
