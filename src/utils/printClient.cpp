#include <Utils.hpp>

void printClient(string msg, Person &user)
{
	int		fd = user.getFd();
	string	color = getColor(fd);

	cout << " ----------------------------------------" << endl;
	cout << color << " [Client " << fd << "]" << DEFAULT << endl;
	cout << " Nickname: " << user.getNickName() << endl;
	cout << " Username: " << user.getUserName() << endl;
	cout << " Realname: " << user.getRealName() << endl;
	cout << " Hostname: " << user.getHostName() << endl;
	cout << " Date: " << getTime() << endl;
	cout << "\n " << MAGENTA + msg + DEFAULT  << endl;
	cout << " ----------------------------------------\n" << endl;
}
