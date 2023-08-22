#include <Commands.hpp>

static string join_input(const vector<string> &input) {
	string str = "";
	for (int i = 3; i < int(input.size()); i++){
		str += input[i] + " ";
	}
	return str;
}

void	sendModeNotice(vector<Person *> &channel, string group, string nickname)
{
	Person	&king = *channel[0];
	for (int i = 0; i < int(channel.size()); i++)
		Response::createMessage().from(king).to(*channel[i]).content("MODE").addContent(group + " +o " + nickname).send();
}

bool	inChannel(vector<Person *> users, string name)
{
	for (int i = 0; i < int(users.size()); i++) {
        if (users[i]->getNickName() == name)
            return true;
    }
    return false;
}

int	cmd::kick(const vector<string> &input, Person & from)
{
	if (input.size() < 3)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(KICK_USE).send();
		return (-1);
	}
	else if (!find_channel(input[1], from))
	{
		Response::withCode(ERR_NOSUCHCHANNEL).to(from).content(input[1] + NO_CHANNEL).send();
		return (-1);
	}
	else if (!isEqual(start.getChannel(input[1])[0]->getNickName(), from.getNickName(), 1))
	{
		Response::withCode(ERR_NOTONCHANNEL).to(from).content(input[0] + NO_OPER).send();
		return (-1);
	}
	else if (!inChannel(start.getChannel(input[1]), input[2]))
	{
		Response::withCode(ERR_USERNOTINCHANNEL).to(from).content(input[2] + " " + input[1] + USER_NOT_IN).send();
		return (-1);
	}
	Person							*to = start.getUserNick(input[2]);
	vector<Person *>				&channel = start.getChannel(input[1]);
	string							msg = "";

	if (input.size() > 3)
		msg = join_input(input);
	else
		msg = "User '" + to->getNickName() + "' left the channel";
	for (int i = 0; i < int(channel.size()); i++)
	{	
		Response::createMessage().from(from).to(*channel[i]).content("KICK ").addContent(input[1] + " " + input[2] + " :" + msg).send();	
		if (channel[i]->getNickName() == to->getNickName())
		{
			from.delOperator(input[1]);
			channel.erase(channel.begin() + i);
			if (channel.size() == 0)
				start.getChannels().erase(input[1]);
			else if (i == 0)
				sendModeNotice(channel, input[1], channel[i]->getNickName());
			i--;
		}
	}
	
	return (0);
}
