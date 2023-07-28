#include <Commands.hpp>

int cmd::list(const vector<string> &input, User& user)
{
	if (user.getActive() != ACTIVE)
		return (-1);
	map < string, vector<User*> >	&group = start.getGroup();
	for (map<std::string, vector<User*> >::iterator g_names : group) //we have to fix because of it's not enough work for client.
	{
		cout << g_names.first << endl;
	}
	return (0);
}
