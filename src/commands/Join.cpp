#include "../../inc/Commands.hpp"

int cmd::join(const vector<string> &input, Server &srv, User& user)
{
	if (user.getActive() != ACTIVE)
		return (-1);
	
	cout << "join" << endl;
	return (0);
}
