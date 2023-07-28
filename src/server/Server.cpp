#include <Server.hpp>

Server::Server() {}

void	Server::toBegin()
{
	for (int i = 0; i < 5; i++)
		users.push_back(0);
	setUpSocket();
}

Server::~Server()
{
	cout << "it is not done but work destructor" << endl;
}

const string	Server::getPassword() const { return (this->password); }

map< string, vector<User*> >	&getGroup() { return (this->group); }

vector<User*>	Server::getChannel(const string &channel) { return (this->group[channel]); }

void			Server::setPort(int port) { this->port = port; }

void			Server::setPassword(string pass) { this->password = pass; }

map< string, vector<User*> >	&getGroup() { return (this->group); }