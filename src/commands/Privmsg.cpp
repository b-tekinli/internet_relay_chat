#include <Commands.hpp>

void	sendGroup(const User& user, string n_channel, Reply res ,string msg)
{
	vector<User*>	group = start.getChannel(n_channel);

	for (int i = 0; group[i]; i++)
	{
		Response::create().from(user).to(*group[i]).code(res).content(msg).send();
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
	if (input.size() > 2 && from.getActive() != ACTIVE)
	{
		Response::create().to(from).code()
		return (-1);
	}
	string	who = input[1];
	string	msg = str_merge(input);

	if (who[0] == '#')
		sendGroup(from, who, ERR_NORECIPIENT, msg);
	else
	{
		User *to = start.getUserNick(input[1]);

		Response::create().from(from).to(*to).code(ERR_NORECIPIENT).content(msg).send();
		//write_fd(start.getUserNick(who)->getFd(), NO_PASS);
	}
	return (0);
}
