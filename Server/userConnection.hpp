#ifndef USERCONNECTION_HPP
#define USERCONNECTION_HPP
/** \file userConnection.hpp */
#include "session.hpp"

/**
	\brief Class for the user connection.
	Class that takes cares of user requests.
	
	\author Salizer
	\date 19/10 -11
	\copyright GPL 2.0
*/
class UserConnection
{
	private:
	unsigned int id; // Used for tagging segments

	public:
	UserConnection();
	~UserConnection();
};
#endif
