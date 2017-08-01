/*************************************************************************
	> File Name: libyff_io.c
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 20时52分21秒
 ************************************************************************/

#include "head_io.h"

ssize_t yff_read(int fd , void * buf , size_t qty)
{
    int result;
    
    result = read(fd , buf , qty);
    if(result == -1)
        perror("yff_read");

    return result;
}
