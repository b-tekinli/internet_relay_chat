#include <Commands.hpp>

int cmd::list(const vector<string> &input, User& user)
{
	if (user.getActive() != ACTIVE)
		return (-1);
	return (0);
}
