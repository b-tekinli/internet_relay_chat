#include "../../inc/Commands.hpp"

int cmd::ping(const vector<string> &input, User &user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PING <nickName>" << endl;
		return (1);
	}

	string nickName = user.getNickName();

	cout << "PING " << nickName << endl;

	ostringstream oss;
	int fd = user.getFd();
	oss << fd;

	const string strFd = oss.str().c_str();


	Response::create().content(strFd +  " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();

	user.message = input[2];

	return (0);
}
