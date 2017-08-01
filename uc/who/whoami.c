/*************************************************************************
	> File Name: whoami.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月07日 星期五 14时12分00秒
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

int main()
{
    struct passwd *one;
    one = getpwuid(getuid());
    puts(one->pw_name);


    return 0;
}
