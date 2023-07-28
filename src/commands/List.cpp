#include <Commands.hpp>

int cmd::list(const vector<string> &input, User& user)
{
	if (user.getActive() < HALF)
	{
		write_fd(user.getFd(), NO_PASS);
		return (-1);
	}	
	map < string, vector<User*> >	&group = start.getGroup();
	std::map<std::string, vector<User*> >::iterator it = group.begin();

	for (; it != group.end(); it++) //we have to fix because of it's not enough work for client.
	{
		cout << it->first << endl;
	}
	return (0);
}
