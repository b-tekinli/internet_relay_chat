#include <Utils.hpp>

void	sendModeNotice(vector<Person *> &channel, string group, string nickname)
{
	Person	&king = *channel[0];
	for (int i = 0; i < int(channel.size()); i++)
		if (channel[i] != NULL)
			Response::createMessage().from(king).to(*channel[i]).content("MODE").addContent(group + " +o " + nickname).send();
}
