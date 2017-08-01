/*************************************************************************
	> File Name: remote_ls.c
	> Author: 
	> Mail: 
	> Created Time: Sun Jul 16 09:19:58 2017
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>

#define oops(msg) {perror(msg); exit(EXIT_FAILURE);}
#define PORT 15000

int main(int argc , char *argv[])
{
    int sock_fd;
    sock_fd = socket(AF_INET , SOCK_STREAM , 0);
    if(sock_fd == -1)
    {
        oops("socket");
    }

    struct sockaddr_in server;
    bzero(&server , sizeof server);

    struct hostent *server_host;
    server_host = gethostbyname(argv[1]);
    if(server_host == NULL)
    {
        oops("gethostbyname");
    }

    bcopy(server_host->h_addr , (struct sockaddr *)&server.sin_addr , server_host->h_length);//copy addr
    server.sin_port = htons(PORT);
    server.sin_family = AF_INET;

    if(connect(sock_fd , (struct sockaddr *)&server , sizeof server) != 0)
    {
        oops("connect");
    }

    if(write(sock_fd , argv[2] , strlen(argv[2])) == -1)
    {
        oops("write");
    }
    
    if(write(sock_fd , "\n", 1) == -1)
    {
        oops("write");
    }

    char buffer[BUFSIZ];
    int result;
    while(  (result = read(sock_fd , buffer , BUFSIZ)) > 0)
    {
        if(write(1 , buffer , result) == -1)
        {
            oops("write");
        }
    }

    close(sock_fd);

    return 0;
}
