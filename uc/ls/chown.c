/*************************************************************************
	> File Name: chown.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月08日 星期六 17时24分34秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>

int main(int argc , char *argv[])
{
    int result;
    struct passwd *one;
    one = getpwnam(argv[1]);
  if(one == NULL)
    {
        printf("user is not exist!\n");
      return 2;
    }
    result = chown(argv[2] , one->pw_uid , getgid());

    if(result == -1)
    {
        perror("file");
        return 1;
    }

    return 0;
}
