#include "userConnection.hpp"

UserConnection::UserConnection(int fd, Session *sess)
{
	fdClient = fd;
	sessServer = sess;
	
	if(authUser() == false)
	{
		// What to do if no authoriate
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