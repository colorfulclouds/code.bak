/*************************************************************************
	> File Name: getpwnam.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 09时03分33秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
    struct passwd *one;
    one = getpwnam(argv[1]);

    if(one == NULL)
    {
        perror("get");
        return 1;
    }
    else
    {
        printf("uid:%d\n", one->pw_uid);
    }


    return 0;
}
