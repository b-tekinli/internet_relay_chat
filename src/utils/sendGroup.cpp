#include <Utils.hpp>

void	sendGroup(Person & user, const string n_channel, const string msg)
{
	vector<Person *>	&group = start.getChannel(n_channel);

	for (int i = 0; i < int(group.size()); i++)
	{
		if (group[i] != NULL && user.getNickName() != group[i]->getNickName())
			Response::createMessage().from(user).to(*group[i]).content(msg).send();
	}
}
