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
	Response::create().content(to_string(user.getFd()) +  " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();
//        this->send_user(uc->get_fd(), "SERVER :" + uc->getFullname() + " PONG :" + uc->getNickname());


	user.message = input[2];



	return (0);
}
