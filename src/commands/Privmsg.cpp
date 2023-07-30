#include "../../inc/Commands.hpp"

void	sendGroup(const User user, string n_channel, int num, int cod ,string msg)
{
	vector<User*>	group = start.getChannel(n_channel);

	for (int i = 0; group[i]; i++)
	{
		write_fd(group[i]->getFd(), generateReply(cod, user, n_channel + ""));
	}
}

string	str_merge(const vector<string> &input)
{
	int		i = 2;
	string	merge;

	for (; input[i]; i++)
	{
		merge += input[i];
	}
	return (merge);
}

int cmd::privmsg(const vector<string> &input, User& user)
{
	if (input.size() > 2 && user.getActive() != ACTIVE)
	{
		return (-1);
	}
	string	who = input[1];
	string msg = str_merge(input);

	if (who[0] == '#')
		sendGroup(user, who, 2, ERR_NORECIPIENT, msg);
	else
	{
		write_fd(start.getUserNick(who)->getFd(), NO_PASS);
	}
	return (0);
}
