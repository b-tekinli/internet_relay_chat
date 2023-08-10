#include <Commands.hpp>

int cmd::privmsg(const vector<string> &input, User& from) // kanallmı ve var mı && kullanıcı mı var mı
{
	if (input.size() < 3)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(PRIVMSG_USE).send();
		return (-1);
	}
	cout << start.getUsers().size() << endl;
	if (start.getUserNick(input[1]) == 0 && !find_channel(input[1], from))
	{
		Response::create().to(from).code(ERR_NOSUCHNICK).content(NO_SUCH).send();
		return (-1);
	}
	string	who = input[1];
	string	msg = just_text();

	if (who[0] == '#')
		sendGroup(from, who, msg); //ERR_NORECIPIENT = look at this
	else
	{
		User *to = start.getUserNick(input[1]);

		Response::withCode(RPL_AWAY).from(from).to(*to).content(msg).send();
	}
	return (0);
}
