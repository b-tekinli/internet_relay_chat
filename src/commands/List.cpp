#include <Commands.hpp>
#include <Response.hpp>
//TODO: handle arguments
int cmd::list(const vector<string> &input, User& user)
{
	if (user.getActive() != ACTIVE)
	{
		//write_fd(user.getFd(), NO_PASS);
		Response::create().code(ERR_NOTREGISTERED).to(user).content("You must register to the server").send();
		return (-1);
	}
	map<string, vector<User *> > &group = start.getChannels();
	Response::create().to(user).code(RPL_LISTSTART).content("TOPIC: \n").send();
	std::map<std::string, vector<User*> >::iterator it = group.begin();

	for (; it != group.end(); it++) //we have to fix because of it's not enough work for client.
	{
		Response::create().to(user).code(RPL_LIST).content(it->first + " :No topic\n").send();
	}
	Response::create().code(RPL_LISTEND).to(user).content(":End of List").send();
	return (0);
}
