#include "../../inc/Commands.hpp"

int cmd::kick(const vector<string> &input, User& from)
{
	if (input.size() != 3)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content("KICK usage 'KICK <channel> <user>'").send();
		return (-1);
	}
	else if (from.getOper() == false)
	{
		Response::withCode(ERR_NOTONCHANNEL).to(from).content(input[0] + NO_OPER).send();
		return (-1);
	}
	else if (!find_channel(input[1], from))
	{
		Response::withCode(ERR_NOSUCHCHANNEL).to(from).content(input[0] + NO_CHANNEL).send();
		return (-1);
	}
	User							*to = start.getUserNick(input[2]);
	vector<User*>					channel = start.getChannel(input[1]);
	int								i = 0;

	Response().create().content(KICK_TO).from(from).to(*to).send();
	for (; i < channel.size(); i++)
	{
		if (channel[i]->getNickName() == to->getNickName())
		{
			delete to;
			channel.erase(channel.begin()+i);
			if (channel.size() == 0)
				start.getChannels().erase(input[1]);
		}
	}
	
	return (0);
}