#include <Commands.hpp>

static string join_input(const vector<string> &input) {
	string str = "";
	for (int i = 0; i < int(input.size()); i++){
		if (i == 2 && input[i][0] != ':')
			str += ":";
		str += input[i] + " ";
	}
	return str;
}

int cmd::privmsg(const vector<string> &input, Person & from)
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

	if (who[0] == '#')
		sendGroup(from, who, join_input(input));
	else
	{
		Person *to = start.getUserNick(input[1]);
		if (to != NULL)
			Response::createMessage().from(from).to(*to).content(join_input(input)).send();
	}
	return (0);
}
