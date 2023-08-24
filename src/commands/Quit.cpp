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
	vector<string>& whChannel = user.getWhichChannel();

	for (int i = 0; i < int(whChannel.size()); i++)
	{
		vector<Person*>	channel = start.getChannel(whChannel[i]);
		
		for (int j = 0; j < int(channel.size()); j++)
		{
			if (channel[i] != NULL)
				Response::createMessage().from(user).to(*channel[i]).content(reason).send();
		}
	}
	Response::createMessage().to(user).content(reason).send();
	start.deleteUser(user.getFd());
	close(user.getFd());
	return 0;
}
