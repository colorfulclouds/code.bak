#ifndef SERVER
#define SERVER
#include "server.h"
#endif

int init_server(struct sockaddr_in *server_info , int port)
{
	int no_use = 1;
	int server_sock_fd;

	server_sock_fd = socket(AF_INET,SOCK_STREAM,0);
	
	if(server_sock_fd == -1)
	{
		printf("fatal error,init socket error\n");
		return -1;
	}

	bzero(server_info,sizeof(struct sockaddr_in));
	
	server_info->sin_family = AF_INET;
	server_info->sin_port = htons(port);	//32165
	server_info->sin_addr.s_addr = inet_addr("10.135.188.26");
	
	//quick restart
	if( ( setsockopt(server_sock_fd , SOL_SOCKET , SO_REUSEADDR , &no_use , sizeof no_use ) ) != 0)  
    {
        printf("fail to set reuseaddr\n"); 
		close(server_sock_fd);
        return -1;  
    }
	//pthread
	if( ( setsockopt(server_sock_fd , SOL_SOCKET , SO_REUSEPORT , &no_use , sizeof no_use ) ) != 0)
	{
		printf("fail to set reuseport\n");
		close(server_sock_fd);		
        return -1; 
	}

	if ( bind(server_sock_fd , (struct sockaddr *)server_info,sizeof(struct sockaddr)) == -1 )
	{
		printf("fail to bind\n");
		close(server_sock_fd);
		return -1;
	}

	listen(server_sock_fd,5);

	return server_sock_fd;
}
