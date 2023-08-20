#include <Commands.hpp>

bool	nameInUse(string name, int _size)
{
	vector<Person *>	users = start.getUsers();

	for (int i = 0; i < users.size() && i < _size; i++)
	{
		if (users[i] && name == users[i]->getNickName())
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
	if (input.size() != 2)
	{
		Response::withCode(ERR_NONICKNAMEGIVEN).to(user).content(NICK_USE).send();
		return (-1);
	}
	if (nameInUse(input[1], user.getFd()))
	{
		Response::withCode(ERR_NICKNAMEINUSE).to(user).content(input[1] + ER_NICK_USED).send();
		return (-1);
	}
	vector<string>& 				wh_channels = user.getWhichChannel();
	string							nickname = input[1];
	map< string, vector<Person*> >&	channels = start.getChannels();

	for (int j = 0; j < wh_channels.size(); j++)
	{
		string				group	= wh_channels[j];
		vector<Person *>	users = channels[group];

		for (int i = 0; i < users.size(); i++)
		{
			int toSend = users[i]->getFd();
			Response::createMessage().to(*users[i]).from(user).content("NICK").addContent(nickname).send();
		}
	}
	
	user.setNickName(input[1]);
	if (user.getActive() == U_HALF)
	{
		Response::create().to(user).code(RPL_WELCOME).content(WELCOME + user.getNickName() + "!" + user.getUserName() + "@127.0.0.1").send();
		user.setActive(ACTIVE);
	}
	return (0);
}
