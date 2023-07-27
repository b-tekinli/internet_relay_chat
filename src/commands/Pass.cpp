#include <Commands.hpp>

void write_fd(int fd, const string &msg)
{
	write(fd,msg.c_str(), msg.length());
}

int cmd::pass(const vector<string> &input, User& user)
{
	cout << "PASS entered" << endl;
	if (user.getActive() == true || input.size() != 2)
		return (-1);
	cout << "TABLE" << endl;
	cout << "password: " << start.getPassword() << endl;
	cout << "password: " << input[1] << endl;
	if (isEqual(input[1], start.getPassword(),1))
	{
		user.setActive(HALF);
		write_fd(user.getFd(),"MESA\n");
		cout << "Password is correct" << endl;
		return (1);
	}
	return (0);
}
