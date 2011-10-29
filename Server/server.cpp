#include "server.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

// Helper functions
// -Prints error message and exits
void printErr(const char *str)
{
	printf("ERROR[%s]: %s\n", str, strerror(errno));
	exit(1);
}

Server::Server()
{
	// Init variables
	sessCurrent = NULL;
	initServer();
}
Server::~Server()
{
	// Clean up
}
void Server::startSession(char *name)
{
	sessCurrent = new Session(name);
	
	// Listen
	if((listen(fdServerSocket, SERVER_BACKLOG)) == -1)
		printErr("Listen");
	
	waitForClients();
}

void Server::startConnection(int fdConnection)
{
	new UserConnection(fdConnection, sessCurrent); // Possible memory leak. Needs way to tell server to delete memory segment.
}
void Server::initServer()
{
	memset(&addrSocket, 0, sizeof(struct sockaddr_in));
	addrSocket.sin_family = AF_INET;
	addrSocket.sin_port = htons(SERVER_PORT);
	addrSocket.sin_addr.s_addr = INADDR_ANY;
	
	if((bind(fdServerSocket, (struct sockaddr*) &addrSocket, sizeof(struct sockaddr_in))) == -1)
		printErr("Binding");
}
void Server::waitForClients()
{
	// Variables
	struct sockaddr_in addrClient;
	socklen_t lenAddr;
	int fdClient;
	
	while(1)
	{
		// Loop where accepts and prints info about IP(inet_ntop). UserConnection can then print info for acceptted users.
		lenAddr = (socklen_t)sizeof(struct sockaddr_in);
		fdClient = accept(fdServerSocket, (struct sockaddr *) &addrClient, &lenAddr);
		if(fdClient == -1)
			printErr("Client connecting");
		startConnection(fdClient);
	}
}