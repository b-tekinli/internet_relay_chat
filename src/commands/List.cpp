#include <Commands.hpp>
#include <Response.hpp>

int cmd::list(const vector<string> &input, User& user)
{
	if (user.getActive() < HALF)
	{
		//write_fd(user.getFd(), NO_PASS);
		return (-1);
	}	
	map < string, vector<User*> >	&group = start.getChannels();
	std::map<std::string, vector<User*> >::iterator it = group.begin();

	Response::create().to(user).code(RPL_LISTSTART).content("TOPIC: \n").send();

	for (; it != group.end(); it++) //we have to fix because of it's not enough work for client.
	{
		Response::create().to(user).content(it->first + " :No topic\n").send();
	}
	Response::create().code(RPL_LIST).to(user).content(":End of List").send();
	return (0);
}
