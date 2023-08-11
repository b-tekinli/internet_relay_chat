#include "../../inc/Commands.hpp"

int cmd::pong(const vector<string> &input, User& user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PONG <nick_name>" << endl;
	}
	string nickName = user.getNickName();

	Response::create().content(user.getFd() +  " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();
	cout << "PONG " << nickName << endl;

	return (0);
}
