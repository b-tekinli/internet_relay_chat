#include <Commands.hpp>

void	sendGroup(Person & user, const string n_channel, const string msg)
{
	vector<Person *>	&group = start.getChannel(n_channel);

	for (int i = 0; i < group.size(); i++)
	{
		if (user.getNickName() != group[i]->getNickName())
			Response::createMessage().from(user).to(*group[i]).content(msg).send();
	}
	Response::withCode(RPL_AWAY).to(user).content("Message sent").send();
}
