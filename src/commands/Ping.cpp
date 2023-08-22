#include <Commands.hpp>

int cmd::ping(const vector<string> &input, Person &user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PING <nickName>" << endl;
		return (1);
	}

	string	nickName = user.getNickName();
	string	strFd = to_str(user.getFd());

	cout << "PING " << nickName << endl;
	Response::createMessage().content("PONG").send();

	user.message = input[2];
	return (0);
}
