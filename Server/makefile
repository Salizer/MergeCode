# Default

Server: server.o userConnection.o session.o main.cpp
	g++  -o Server -pthread main.cpp server.o userConnection.o session.o

server.o: server.hpp server.cpp
	g++ -c server.cpp

userConnection.o: userConnection.hpp userConnection.cpp
	g++ -c userConnection.cpp

session.o: session.hpp session.cpp
	g++ -c session.cpp
