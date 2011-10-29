#include <stdlib.h>
#include <stdio.h>
#include "server.hpp"

int main(int argc, char **argv)
{
	// Variables
	Server theServer;
	
	theServer.startSession("The server");
	
	return(0);
}