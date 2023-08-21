#include <Commands.hpp>

int cmd::pong(const vector<string> &input, Person & user)
{
	if (input.size() < 2)
	{
		cout << "Usage: PONG <nick_name>" << endl;
	}
	string nickName = user.getNickName();

	sendUser(NULL, user, "PONG");
	//Response::create().content(strFd + " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();
	
	cout << "PONG " << user.message << endl;
	/*vector<Person *> &group = start.getUsers();
	for(int  i = 0; group.size() > i ; i++)
	{
		cout << "PONG " << group[i]->message << endl;	
	}*/
	return (0);
}
