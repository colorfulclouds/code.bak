//SERVER
#ifndef HEAD
#define HEAD
#include "head.h"
#endif

#ifndef CONST_VALUE
#define CONST_VALUE
#include "const_value.h"
#endif

struct socket_t
{
	//server use
	struct sockaddr_in client_addr;
	int client_sock_fd_server;
	struct sockaddr_in send_addr;
	int send_sock_fd_server;
	struct sockaddr_in recv_addr;
	int recv_sock_fd_server;

	//client use
	int client_sock_fd_client;
	int send_sock_fd_client;
	int recv_sock_fd_client;
};

int init_server(struct sockaddr_in *server_info , int port);
