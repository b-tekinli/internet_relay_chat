#include "../../inc/Server.hpp"

Server* Server::single_instance = NULL;

Server::Server(int new_port, string new_password): port(new_port), password(new_password)
{
	for (int i = 0; i < 5; i++)
		users.push_back(0);
	single_instance = this;
	setUpSocket();
}


Server::~Server()
{
	cout << "it is not done but work destructor" << endl;
}

Server& Server::getInstance(){
	return *(single_instance);
}

const string	Server::getPassword() const { return (this->password); }

vector<User*>	Server::getChannel(const string &channel) { return (this->group[channel]); }

