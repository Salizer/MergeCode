#ifndef SERVER_HPP
#define SERVER_HPP
/** \file server.hpp */
#include "session.hpp"
#include "userConnection.hpp"

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

	public:
	Server();
	~Server();
	void startSession(const char *name);
	void setupPort(unsigned int port); /// \todo Change argument type
	void waitForClients();

	private:
	void startConnection(/*? conn ,*/ Session *sessServer);
};
#endif
