#include <Server.hpp>
#include <Commands.hpp>

Server::Server() {}

void	Server::toBegin()
{
	
	setUpSocket();
}

Server::~Server() { cout << "it is not done but work destructor" << endl; }

const string					Server::getPassword() const { return (this->password); }

map< string, vector<Person *> >&	Server::getChannels() { return (this->channels); }

vector<Person *>&					Server::getChannel(const string &channel) { return (this->channels[channel]); }

vector<Person *>					 Server::getUsers() { 
	vector<Person *> persons;

	for (int i = 0; i < users.size(); i++){
		if (this->users[i])
			persons.push_back(this->users[i]);
		else
			persons.push_back(NULL);
	}
	return persons;
}

string&							Server::getRawString() { return (raw_string); }

void							Server::setRawString(string set) { raw_string = set; }

void							Server::setPort(int port) { this->port = port; }

void							Server::setPassword(string pass) { this->password = pass; }

void							Server::addUserTo(const string &group, Person &user) 
{
	if (!find_channel(channels[group], user.getNickName()))
		Response::createMessage().from(user).to(user).content("JOIN").addContent(group).send();
	else
	{
		Response::withCode(ERR_USERONCHANNEL).to(user).content(user.getNickName() + " " + group + ER_ALREADY_JOIN).send();
		return ;
	}
	
	if (channels[group].size() == 0)
	{
		cout << "Channel Name: " << group << "." <<endl;
		user.setOper(true);
		user.addOperator(group);
		Response::createMessage().from(user).to(user).content("MODE").addContent(group + " +o " + user.getNickName()).send();
		//Response::withCode(RPL_NOTOPIC).from(user).content(group + NO_TOPIC).send();
	}
	else
	{
		vector<string>	send;

		send.push_back("NOTICE");
		send.push_back(group);
		send.push_back("JOIN " + user.getNickName() + " in the " + group);
		cmd::notice(send, user); //everyone take a message
	}
	cout << "channel before: " << channels[group].size() << "." << endl;
	channels[group].push_back((Person *)&user);
	cout << "channel after: " << channels[group].size() << "." << endl;
	cout << "channel name: " << group << "." << endl;
}

Person *			Server::getUserNick(string nick)
{
	if (users.size() == 0)
		return (NULL);
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i] && users[i]->getNickName() == nick)
			return (users[i]);
	}
	return (NULL);
}

Person *   Server::getOrCreateUser(int fd)
{
	cout << fd << endl;
	cout << users.size() << endl;
	if (users.size() <= fd || users[fd] == 0)
		users[fd] = new Person(fd);
	return (users[fd]);
}

void	Server::deleteUser(int fd)
{
	if (this->users[fd] != 0)
	{
		vector<string>&	wh_op = this->users[fd]->getWhichChannel();

		for (int i = 0; i < wh_op.size(); i++)
		{
			removeUserFrom(wh_op[i], *this->users[fd]);
		}
		delete this->users[fd];
		this->users[fd] = 0;
	}
}

void	Server::removeUserFrom(const string &channel, Person &user)
{
	int fd = user.getFd();
	int i = 0;

	for (; i < channels[channel].size(); i++)
		if (channels[channel][i]->getFd() == fd)
			break;
	channels[channel].erase(channels[channel].begin() + i);
}


