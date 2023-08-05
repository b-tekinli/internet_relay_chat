#include <Commands.hpp>

bool	nameInUse(const string name)
{
	vector<User*>	users = start.getUsers();

	cout << "size: " << users.size() << endl;
	cout << "name: " << name << endl;
	for (int i = -1; i < users.size(); ++i)
	{
		cout << "baktim" << endl;
		if (users[i]->getNickName() == name)
		{
			cout << "girdi" << endl;
			return (true);
		}
	}
	cout << "harbi" << endl;
	return (false);
}

int cmd::nick(const vector<string> &input, User& user)
{
	if (nameInUse(input[1]))
	{
		Response::withCode(ERR_NICKNAMEINUSE).to(user).content(input[1] + NICK_USE).send();
		return (-1);
	}
	if (user.getActive() == HALF)
		Response::create().to(user).code(RPL_WELCOME).content(WELCOME + user.getNickName() + "!"+ user.getUserName() +"@127.0.0.1").send();	
	user.setActive(ACTIVE);
	user.setNickName(input[1]);
	return (0);
}
