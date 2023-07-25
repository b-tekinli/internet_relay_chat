#include "../../inc/Commands.hpp"

void write_fd(int fd, const string &msg){
	write(fd,msg.c_str(),msg.length());
}
int cmd::pass(const vector<string> &input, Server &srv, User& user)
{
	string pasword = "";
	cout << "girdi" << endl;
	if (user.getActive() == true || input.size() != 2)
		return (-1);
	if (input[1] == pasword)
	{
		user.setActive(HALF);
		write_fd(user.getFd(),"MESAJ");
		cout << "Password is correct" << endl;
		return (1);
	}
	return (0);
}
