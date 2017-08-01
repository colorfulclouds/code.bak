/*************************************************************************
	> File Name: popen.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月09日 星期日 21时03分32秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char buff[20];

    fp=popen("who | sort", "r");

    fgets(buff , 20 , fp);
    printf("%s\n", buff);

    pclose(fp);


    return 0;
}
