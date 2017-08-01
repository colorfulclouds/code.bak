/*************************************************************************
	> File Name: sbrk.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月05日 星期三 11时03分59秒
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("pagesize:%d\n", getpagesize());
    int *p = sbrk(0);
    printf("p:%#p\n", p);

    brk(p+8);
    p = sbrk(0);
    printf("after:p:%#p\n", p);
    
    return 0;
}
