#include "../../inc/Server.hpp"

Server::Server(int new_port, string new_password): port(new_port), password(new_password)
{
	setUpSocket();
}

Server::~Server()
{
	cout << "it is not done but work destructor" << endl;
}