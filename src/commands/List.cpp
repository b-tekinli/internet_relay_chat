#include <Commands.hpp>
#include <Response.hpp>
//TODO: handle arguments
int cmd::list(const vector<string> &input, Person & user)
{
	if (user.getActive() != ACTIVE)
	{
		Response::create().code(ERR_NOTREGISTERED).to(user).content("You must register to the server").send();
		return (-1);
	}
	map<string, vector<Person *> >	&group = start.getChannels();
	std::map<std::string, vector<Person *> >::iterator it = group.begin();
	string		str = "322 channel1 50 :A discussion about programming\r\n";
	Response::create().to(user).code(RPL_LISTSTART).content("TOPIC: \n").send();
	for (; it != group.end(); it++) // we have to fix because of it's not enough work for client.
	{
		if (input.size() == 1)
		{
			Response::create().to(user).code(RPL_LIST).content(str).send();
			write(user.getFd(), str.c_str(), str.size());
		}
		else if (input[1] == it->first)
		{
			Response::create().to(user).code(RPL_LIST).content(it->first + " :No topic\r\n").send();
		}
	}
	Response::create().code(RPL_LISTEND).to(user).content("End of List\n").send();
	return (0);
}

