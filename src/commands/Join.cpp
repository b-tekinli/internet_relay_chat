#include <Commands.hpp>

int cmd::join(const vector<string> &input, User& user)
{
	cout << user.getActive() << endl;
	if (user.getActive() < HALF)
	{
		write_fd(user.getFd(), NO_PASS);
		return (-1);
	}
	write(user.getFd(), "join", 4);
	users::addUserTo(input[1], user, start.getGroup());
	return (0);
}
