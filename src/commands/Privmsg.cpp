#include <Commands.hpp>

bool	check_channel(string )
{

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
	if (start.getUserNick(input[1]) == 0 || check_channel())
	{
	}

	string	who = input[1];
	string	msg = str_merge(input);

	if (who[0] == '#')
		sendGroup(from, who, ERR_NORECIPIENT, msg); //ERR_NORECIPIENT = look at this
	else
	{
		User *to = start.getUserNick(input[1]);

		Response::create().from(from).to(*to).content(msg).send();
	}
	return (0);
}
