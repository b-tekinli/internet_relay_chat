#include <Commands.hpp>

void	sendGroup(Person & user, const string n_channel, const string msg)
{
	vector<Person *>	&group = start.getChannel(n_channel);

	for (int i = 0; i < group.size(); i++)
	{
		Response::withCode(RPL_AWAY).from(user).to(*group[i]).content(msg).send();
	}
}
