//gcc server.c -o server -lws2_32 -Wall

#include <stdio.h>
#include <windows.h>
#include <winSock2.h>

//#pragma comment(lib, "Ws2_32.lib")

SOCKET init_tcp()
{
	WSADATA wsaDATA;
	int retval = WSAStartup(0x202, &wsaDATA);
	if (retval != 0)
	{
		return INVALID_SOCKET;
	}
		
	printf("Server: WSAStartup() is OK.\n");
	
	//=====================================================
	SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if(server_socket == INVALID_SOCKET)
	{
		return INVALID_SOCKET;
	}
	return server_socket;
}

SOCKET open_tcp(SOCKET server_socket, unsigned short port)
{
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY; 	//"192.168.88.1";
	address.sin_port = htons(port);  //0001 => 1 || 1000 => 1
	
	int retval = bind(server_socket, (struct sockaddr*)&address,
		sizeof(address));
	
	if(retval != 0)
	{
		return INVALID_SOCKET;
	}
	
	printf("Server: bind() is OK. \n");
	//=====================
	retval = listen(server_socket, 5);
	if(retval == SOCKET_ERROR)
	{
		return INVALID_SOCKET;
	}
	
	printf("Server: listen() is OK.\n");
	return server_socket;
}

int recievce_tcp(SOCKET channel, char Buffer[], int length)
{
	int retval = recv(channel, Buffer, length, 0);
	return retval;
}

int send_tcp(SOCKET channel, char Buffer[], int length)
{
	int retval = send(channel, Buffer, length, 0);
	return retval;
}

int main()
{
	//1. init socket : Connection Type (TCP, UDP)
	SOCKET server_socket = init_tcp();
	//2. open socket :  IP+PORT, BIND, Listen 
	server_socket = open_tcp(server_socket, 7777);
	if(server_socket == INVALID_SOCKET)
	{
		printf("Server: open socket faild.\n");
		return -1;
	}
	
	while (TRUE)
	{
		//3. Wait for new client : accept
		printf("Server: wating for client...\n");
		struct sockaddr_in client_info;
		int client_info_length = sizeof(client_info);
		SOCKET channel = accept(server_socket, (struct sockaddr*)&client_info, &client_info_length);
		if(channel == INVALID_SOCKET)
		{
			printf("Server: accept() faild.\n");
			return -1;
		}
		printf("Server: accept() is OK.\n");
		printf("Server: client ip: %s, port: %d\n",
			inet_ntoa(client_info.sin_addr),
			htons(client_info.sin_port)
			);
		 
		//4. recieve, send 
		char Buffer[128];
		int retval  = recievce_tcp(channel, Buffer, sizeof(Buffer));
		if(retval  == SOCKET_ERROR)
		{
			printf("Server: recieve faild.\n");
			continue;
		}
		
		if(retval == 0)
			printf("Server: client closed connection.\n");
		
		printf("Server: recieve: %s\n", Buffer);
		retval = send_tcp(channel, Buffer, sizeof(Buffer));
		if(retval == SOCKET_ERROR)
			printf("Server: send of\n");
		
		//5. close
		closesocket(channel);
		printf("Server: I'm waiting more connection, try running the client\n");
	}
	
	return 0;
	
}