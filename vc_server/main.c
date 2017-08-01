#ifndef HEAD
#define HEAD
#include "head.h"
#endif

#ifndef SERVER
#define SERVER
#include "server.h"
#endif

#ifndef CONST_VALUE
#define CONST_VALUE
#include "const_value.h"
#endif

int main(void)
{
	struct socket_t v;	//socket set
	
	v.client_sock_fd_server = init_server(&(v.client_addr) , CLIENT_PORT);
	if(v.client_sock_fd_server == -1)
		return -1;
	
	v.send_sock_fd_server = init_server(&(v.send_addr) , SEND_PORT);
	if(v.send_sock_fd_server == -1)
		return -1;
	
	v.recv_sock_fd_server = init_server(&(v.recv_addr) , RECV_PORT);
	if(v.recv_sock_fd_server == -1)
		return -1;
	
	v.client_sock_fd_client = accept(v.client_sock_fd_server , NULL , NULL);
	v.send_sock_fd_client = accept(v.send_sock_fd_server , NULL , NULL);
	v.recv_sock_fd_client = accept(v.recv_sock_fd_server , NULL , NULL);
	
	return 0;
}