#include <stdio.h>
#include <winSock2.h>
#include <windows.h>

//gcc server.c -o server -lws2_32 -Wall

SOCKET init_tcp()
{
	WSADATA wsaData;
	//Check if Operating System support WS2_32.LIB
	int retval = WSAStartup(0x202,   // version number 2.2
		&wsaData // struct contain DLL configuration information
		);
	if (retval != 0)
	return INVALID_SOCKET;
	printf("Server: WSAStartup() is OK.\n");
	
	//=======================================================
	// TCP socket
	SOCKET channel = socket(AF_INET, SOCK_STREAM, 0);
	if(channel == INVALID_SOCKET)
	{
		return INVALID_SOCKET;
	}
	return channel;
}

SOCKET open_tcp(SOCKET channel,  char* server_ip, unsigned short server_port)
{
	unsigned int addr = inet_addr(server_ip);
	struct hostent *hp;
	hp = gethostbyaddr((char *)&addr, 4, AF_INET);
	if (hp == NULL)
	{
		return INVALID_SOCKET;
	}	
	
	struct sockaddr_in address;
	memset(&address, 0, sizeof(address));
	memcpy(&(address.sin_addr), hp->h_addr, hp->h_length);
		
	address.sin_family = hp->h_addrtype;
	address.sin_addr.s_addr = INADDR_ANY; 	//"192.168.88.1";
	address.sin_port = htons(server_port);  //0001 => 1 || 1000 => 1
	
	int retval = connect(channel, (struct sockaddr*)&address, sizeof(address));
	if(retval == SOCKET_ERROR)
	{
		return INVALID_SOCKET;
	}
	printf("Cliente: connect is OK.\n");
	return channel;
}

int recievce_tcp(SOCKET channel, char Buffer[], int length)
{
	int retval = recv(channel, Buffer, length, 0);
	return retval;
}

int send_tcp(SOCKET channel, char Buffer[], int length)
{
	int retval = send(channel, Buffer, length, 0);
	if (retval == SOCKET_ERROR)
		return SOCKET_ERROR;
	return retval;
}

int main()
{
	SOCKET channel = init_tcp();
	if(channel == INVALID_SOCKET)
	{
		printf("Client: init() faild.\n");
		return -1;
	}
	char *server_ip = "127.0.0.1";
	unsigned short server_port = 7777;
	open_tcp(channel, server_ip, server_port);
	if(channel == INVALID_SOCKET)
	{
		printf("Client: open_tcp() faild.\n");
		return -1;
	}
	printf("Please enter your message:\n");
	char line[128];
	line[0] = '\0';
	line[sizeof(line)-1] = ~'\0';
	fgets(line, sizeof(line), stdin);
	//===============================
	char Buffer[128];
	wsprintf(Buffer, line);
	int retval = send_tcp(channel, Buffer, sizeof(Buffer));
	if(retval == SOCKET_ERROR)
	{
		printf("Client: send_tcp() faild.\n");
		return -1;
	}
	
	memset(&Buffer, 0, sizeof(Buffer));
	retval = recievce_tcp(channel, Buffer, sizeof(Buffer));
	if(retval == SOCKET_ERROR)
	{
		printf("Client: recieve() faild.\n");
		closesocket(channel);
	}
	else if (retval == 0)
	{
		printf("Client: Server closed connection.\n");
		closesocket(channel);
	}
	else
	{
		printf("Client: Recieved: %s\n", Buffer);
	}
	closesocket(channel);
	system("pause");
	return 0;
}