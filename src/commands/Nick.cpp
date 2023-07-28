#include <Commands.hpp>

int cmd::nick(const vector<string> &input, User& user)
{
	if (user.getActive() < HALF)
	{
		write_fd(user.getFd(), NO_PASS);
		return (-1);
	}
	user.setActive(ACTIVE);
	user.setNickName(input[1]);
	return (0);
}
