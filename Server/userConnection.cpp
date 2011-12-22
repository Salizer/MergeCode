#include "userConnection.hpp"
#include <stdio.h>

// Prototypes
// -Thread for user
void *waiting(void *data);

UserConnection::UserConnection(int fd, Session *sess)
{
	fdClient = fd;
	sessServer = sess;
	
	if(authUser() == false)
	{
		// What to do if no authoriate
	}
	else
	{
		pthread_create(&tIDConnection, NULL, waiting, (void *)this);
		pthread_detach(tIDConnection);
	}
}

UserConnection::~UserConnection()
{
	// Clean up
}

bool UserConnection::authUser() // Needs implementation
{
	return(true);
}

ssize_t UserConnection::readFromStream(char buffer[])
{
	return(read(fdClient, buffer, MAX_PACKAGE_SIZE));
}

void *waiting(void *data)
{
	// Variables
	UserConnection *connection = NULL;
	char readingBuffer[MAX_PACKAGE_SIZE];
	ssize_t status;
	
	// Init
	connection = (UserConnection *)data;
	
	// Wait
	while(1)
	{
		status = connection->readFromStream(readingBuffer);
		if(status == -1) // Error
		{
			perror("Reading from client");
			delete connection;
			_exit(1);
		}
		else if(status == 0) // Connection broke
		{
			puts("User disconnected");
			delete connection;
			_exit(0);
		}
		printf("Read: %s\n", readingBuffer);
	}
}