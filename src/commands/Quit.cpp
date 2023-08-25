#include <Commands.hpp>

static string join_input(const vector<string> &input) {
	string str = "";
	for (int i = 1; i < int(input.size()); i++){
		str += input[i] + " ";
	}
	return str;
}

int cmd::quit(const vector <string> &input, Person &user)
{
	string reason = "QUIT :";

	if (input.size() > 1)
		reason += join_input(input);
	else
		reason += "Gone to have lunch";
	vector<string>	channels = user.getWhichChannel();
	if (channels.size() > 0)
	{
		for (vector<string>::size_type i = 0; i < channels.size(); i++)
		{
			sendGroup(user, channels[i], reason);
			start.removeUserFrom(channels[i], user);
		}
	}
	Response::createMessage().to(user).content(reason).send();
	start.deleteUser(user.getFd());
	close(user.getFd());
	return 0;
}
