#include <Commands.hpp>

int cmd::pong(const vector<string> &input, Person & user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PONG <nick_name>" << endl;
	}
	string nickName = user.getNickName();

	sendUser(NULL, user, "PONG");
	cout << "PONG " << user.message << endl;
	return (0);
}
