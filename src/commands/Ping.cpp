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

	return (0);
}
