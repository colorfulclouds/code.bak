/*************************************************************************
	> File Name: head_io.h
	> Author: 
	> Mail: 
	> Created Time: 2017年07月03日 星期一 20时58分26秒
 ************************************************************************/

#ifndef _HEAD_IO_H
#define _HEAD_IO_H
#include <stdio.h>
#include <fcntl.h>

ssize_t yff_read(int fd , void * buf , size_t qty); 
#endif
