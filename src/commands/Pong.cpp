#include "../../inc/Commands.hpp"

int cmd::pong(const vector<string> &input, User& user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PONG <nick_name>" << endl;
	}
	
	string nickName = user.getNickName();

	cout << "PONG " << nickName << endl;


	return (0);
}
