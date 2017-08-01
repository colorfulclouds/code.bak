/*************************************************************************
	> File Name: getwinsize.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月08日 星期六 15时55分11秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

int main()
{
    struct winsize size;
    ioctl(STDOUT_FILENO , TIOCGWINSZ , &size);

    printf("%d : %d\n", size.ws_col , size.ws_row);

    return 0;
}
