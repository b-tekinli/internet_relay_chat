#include "../../inc/Commands.hpp"

int cmd::nick(const vector<string> &input, User& user)
{
	if (user.getActive() < HALF)
		return (-1);
	cout << "I'm a nick" << endl; 
	user.setActive(ACTIVE);
	user.setNickName(input[1]);
	cout << "nick" << endl;
	return (0);

}
