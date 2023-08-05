#include <Server.hpp>
#include <Commands.hpp>

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

map< string, vector<User*> >& Server::getChannels() { return (this->channels); }

vector<User*>	Server::getChannel(const string &channel) { return (this->channels[channel]); }

const vector<User*>&			Server::getUsers() const { return (this->users); }

void			Server::setPort(int port) { this->port = port; }

void			Server::setPassword(string pass) { this->password = pass; }

void			Server::addUserTo(const string &group, User &user) 
{
	if (channels[group].size() == 0)
	{
		user.setOper(true);
		user.addOperator(group);
	}
	else
	{
		vector<string>	send;

		send.push_back("NOTICE");
		send.push_back(group);
		send.push_back("JOIN " + user.getNickName() + " in the " + group);
		cmd::notice(send, user); //every one take a message
	}
	channels[group].push_back((User *)&user); 
}

User*			Server::getUserNick(string nick)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i]->getNickName() == nick)
			return (users[i]);
	}
	return (0);
}

User*   Server::getOrCreateUser(int fd)
{
	if (users.size() < fd || users[fd] == 0)
		users.insert(users.begin() + fd, new User(fd));
	return (users[fd]);
}

void Server::deleteUser(int fd)
{
	if (this->users[fd] != 0)
	{
		delete this->users[fd];
		this->users[fd] = 0;
	}
}

void Server::removeUserFrom(const string &channel, User &user)
{
	int fd = user.getFd();

	delete channels[channel][fd];
	channels[channel][fd] = NULL;
}
