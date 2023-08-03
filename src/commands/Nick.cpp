#include <Commands.hpp>

int cmd::nick(const vector<string> &input, User& user)
{
	 if (user.getActive() == HALF)
		Response::create().to(user).code(RPL_WELCOME).content(WELCOME + user.getNickName() + "!kvirc@127.0.0.1").send();	
	user.setActive(ACTIVE);
	user.setNickName(input[1]);
	return (0);
}
