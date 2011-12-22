#ifndef SERVER_HPP
#define SERVER_HPP
/** \file server.hpp */
#include "session.hpp"
#include "userConnection.hpp"
#include <sys/socket.h>
#include <netinet/in.h>

// Server settings
#define SERVER_PORT 1847 // Later check what default port to use plus make user able to set it
#define SERVER_BACKLOG 4

/**
	\brief Class for server.
	The class takes care of initial connections from clients and handling them with UserConnection.
	It also have the responsibility of setting up the session.
	
	\author Salizer
	\date 19/10 -11
	\copyright GPL 2.0
*/
class Server
{
	private:
	Session * sessCurrent;
	int fdServerSocket;
	struct sockaddr_in addrSocket;

	public:
	Server();
	~Server();
	/**
		\brief Starts new session and waits for clients.
		
		\pre 'name' is not null.
		\post A new session i started with given name and the server starts waiting for clients.
	*/
	void startSession(const char *name);

	private:
	void startConnection(int fdConnection); /// \warning Possible memory leak.(Now thread cleans it)
	void initServer(); // To set up the server for use
	void waitForClients();
};
#endif
