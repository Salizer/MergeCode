#ifndef SESSION_HPP
#define SESSION_HPP
#include <string>

/** \file session.hpp */
/**
	\brief Server session class.
	Class that contains info about a server session.
	Things like name, users and most importantly the actual text.
	
	\author Salizer
	\date 19/10 -11
	\copyright GPL 2.0
*/
class Session
{
	private:
	std::string name;
	//struct User *userList; // Maybe linked list or vector /// \todo Find data structure
	// ? text;	// Maybe linked list /// \todo Find data structure

	public:
	Session(const char *name);
	~Session();
};
#endif
