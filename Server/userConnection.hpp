#ifndef USERCONNECTION_HPP
#define USERCONNECTION_HPP
/** \file userConnection.hpp */
#include "session.hpp"
#include <pthread.h>

#define MAX_PACKAGE_SIZE 1024 // Should be used for maximum when sending packages.

/**
	\brief Class for the user connection.
	Class that takes cares of user requests.
	
	\author Salizer
	\date 19/10 -11
	\copyright GPL 2.0
*/
class UserConnection
{
	public:
	UserConnection(int fd, Session *sess);
	~UserConnection();
	
	/** \brief Read from stream.
	
	*/
	ssize_t readFromStream(char buffer[]);
	
	private:
	bool authUser();
	unsigned int id; // Used for tagging segments
	int fdClient;
	Session *sessServer;
	pthread_t tIDConnection;
};
#endif
