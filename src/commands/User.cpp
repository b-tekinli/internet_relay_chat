#include "../../inc/Commands.hpp"

int cmd::user(const vector<string> &input, User& user) // boşluk olunca farklı sonuç
{
	if (input.size() != 5)
	{
		Response::create().to(user).code(ERR_NEEDMOREPARAMS).content(input[0] + NOT_ENOUGH).send();
		return (-1);
	}
	else if (user.getActive() == HALF)
		user.setActive(U_HALF);
	user.setUserName(input[1]);
	user.setHostName(input[2]);
	user.setServName(input[3]);
	user.setRealName(input[4]);
	return (0);

}
