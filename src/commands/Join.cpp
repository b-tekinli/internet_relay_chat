#include "../../inc/Commands.hpp"

int cmd::join(const vector<string> &input, User& user)
{
	cout << "girdi" << endl;
	cout << user.getActive() << endl;
	if (user.getActive() != ACTIVE)
		return (-1);
	write(user.getFd(), "join", 4);
	return (0);
}
