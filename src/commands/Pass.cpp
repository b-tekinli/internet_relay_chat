#include "../../inc/Global.hpp"

int cmd::pass(const vector<string> &input, User &user)
{
	string pasword = "";
	cout << "girdi" << endl;
	if (user.getActive() == true || input.size() != 2)
		return (-1);
	if (input[1] == pasword)
	{
		user.setActive(HALF);
		cout << "Password is correct" << endl;
		return (1);
	}
	return (0);
}
