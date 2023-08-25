#include <Commands.hpp>

bool	nameInUse(string name)
{
	vector<Person *>	users = start.getUsers();

	for (int i = 0; i < int(users.size()); i++)
	{
		if (users[i] && isEqual(name, users[i]->getNickName(), 1))
			return (true);
	}
	return (false);
}

int cmd::nick(const vector<string> &input, Person & user)
{
	if (user.getActive() < U_HALF)
	{
		Response::create().to(user).content(FIRST_USERSET).send();
		return (-1);
	}
	else if (input.size() != 2)
	{
		Response::withCode(ERR_NONICKNAMEGIVEN).to(user).content(NICK_USE).send();
		return (-1);
	}
	else if (nameInUse(input[1]))
	{
		Response::withCode(ERR_NICKNAMEINUSE).to(user).content(input[1] + ER_NICK_USED).send();
		return (-1);
	}
	vector<string>& 				wh_channels = user.getWhichChannel();
	string							nickname = input[1];
	map< string, vector<Person*> >&	channels = start.getChannels();

	for (int j = 0; j < int(wh_channels.size()); j++)
	{
		string				group	= wh_channels[j];
		vector<Person *>	users = channels[group];

		for (int i = 0; i < int(users.size()); i++)
			if (users[i] != NULL)
				Response::createMessage().to(*users[i]).from(user).content("NICK ").addContent(nickname).send();
	}
	user.setNickName(nickname);
	if (user.getActive() == U_HALF)
	{
		Response::create().to(user).code(RPL_WELCOME).content(WELCOME + user.getNickName() + "!" + user.getUserName() + "@127.0.0.1").send();
		Response::createReply(RPL_YOURHOST).to(user).content("Your host is " + start.getHostname() + ", running " + VERSION).send();
		Response::createReply(RPL_CREATED).to(user).content("This server was created " + getTime()).send();
		user.setActive(ACTIVE);
	}
	return (0);
}
