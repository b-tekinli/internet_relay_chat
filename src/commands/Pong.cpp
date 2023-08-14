#include "../../inc/Commands.hpp"

int cmd::pong(const vector<string> &input, User& user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PONG <nick_name>" << endl;
	}
	string nickName = user.getNickName();

	ostringstream oss;
	int fd = user.getFd();
	oss << fd;

	const string strFd = oss.str().c_str();

	Response::create().content(strFd + " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();
	
	cout << "PONG " << user.message << endl;
	/*vector<User *> &group = start.getUsers();
	for(int  i = 0; group.size() > i ; i++)
	{
		cout << "PONG " << group[i]->message << endl;	
	}*/
	return (0);
}
