#include <Commands.hpp>

bool	find_channel(string target, User &from)
{
	if (target[0] != '#')
		return (false);
	map < string, vector<User*> > search = start.getChannels();
	std::map<std::string, vector <User*> >::iterator it = search.begin();	

	for (; it != search.end(); it++)
	{
		if (it->first == target)
		{
			for (int i = 0; it->second[i]; i++)
			{
				if (it->second[i]->getNickName() == from.getNickName())
					return (true);
			}
			Response::create().content(NO_MEM + target + "\n").send();
		}
	}
	return (false);
}

void	sendGroup(const User& user, string n_channel, string msg)
{
	vector<User*>	group = start.getChannel(n_channel);

	for (int i = 0; group[i]; i++)
	{
		Response::create().from(user).to(*group[i]).content(msg).send();
	}
}

string	str_merge(const vector<string> &input)
{
	int		i = 2;
	string	merge = "";

	for (; i < input.size(); i++)
	{
		merge += input[i];
		if (i < input.size() - 1)
			merge += " ";
	}
	return (merge);
}

int cmd::privmsg(const vector<string> &input, User& from)// kanallmı ve var mı && kullanıcı mı var mı
{
	if (input.size() > 2)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(input[0] + NOT_ENOUGH).send();
		return (-1);
	}
	if (start.getUserNick(input[1]) == 0)
	{
		Response::create().to(from).code(ERR_NOSUCHNICK).content(NO_SUCH).send();
		return (-1);
	}
	string	who = input[1];
	string	msg = str_merge(input);

	if (who[0] == '#')
		sendGroup(from, who, msg); //ERR_NORECIPIENT = look at this
	else
	{
		User *to = start.getUserNick(input[1]);

		Response::create().from(from).to(*to).content(msg).send();
	}
	return (0);
}


int cmd::privmsg(const vector<string> &input, User& from)
{
	if (input.size() > 2)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(input[0] + NOT_ENOUGH).send();
		return (-1);
	}
	if (!find_channel(input[1], from))
	{
		Response::create().to(from).code(ERR_NOSUCHNICK).content(NO_SUCH).send();
		return (-1);
	}
}
