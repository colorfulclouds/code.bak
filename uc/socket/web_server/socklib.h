/*************************************************************************
	> File Name: socklib.h
	> Author: 
	> Mail: 
	> Created Time: Sun Jul 16 15:02:19 2017
 ************************************************************************/

#ifndef _SOCKLIB_H
#define _SOCKLIB_H
//head files
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
//define
#define HOSTLEN 256
#define BACKLOG 1
//function
int make_server_socket_q(int portnum , int backlog);
int make_server_socket(int portnum);
int connect_to_server(char *host , int portnum);

#endif
