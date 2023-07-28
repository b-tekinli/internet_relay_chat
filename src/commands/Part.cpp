#include <Commands.hpp>

void write_fd(int fd, const string &msg)
{
	write(fd,msg.c_str(), msg.length());
}

int cmd::part(const vector<string> &input, User& user)
{
	if (user.getActive() == true || input.size() != 2)
		return (-1);
	users::removeUserFrom(input[1], user, start.getGroup());
	return (0);
}
