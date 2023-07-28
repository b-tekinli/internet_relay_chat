#include <Commands.hpp>

int cmd::list(const vector<string> &input, User& user)
{
	if (user.getActive() != ACTIVE)
		return (-1);
	map < string, vector<User*> >	&group = start.getGroup();
	for (map<std::string, int>::iterator g_names : map) //we have to fix because of it's not enough work for client.
	{
		cout << first << endl;
	}
	return (0);
}
