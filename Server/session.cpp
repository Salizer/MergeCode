#include "session.hpp"
#include <string.h>

Session::Session(const char *name)
{
	this->name = name;
}
Session::~Session()
{
	// Clean up
}