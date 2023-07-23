#include "../../inc/Server.hpp"

Server::Server(int port, string password): port(port), password(password)
{
	for (int i = 0; i < 3; i++)
	{
		User person(0);
		all_user.push_back(person);
	}
	setUpSocket();
}

Server::~Server()
{
	cout << "it is not done but work destructor" << endl;
}