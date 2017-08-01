/*************************************************************************
	> File Name: sizeof_d_name.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月07日 星期五 21时00分05秒
 ************************************************************************/
//thsi is a test modify
#include<stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    struct dirent one;

    printf("length:%d\n", sizeof(one.d_name) );

    return 0;
}
