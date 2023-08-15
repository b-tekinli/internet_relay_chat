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
	Response::create().content(strFd +  " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();

	user.message = input[2];
	/*vector<Person *> &group = start.getUsers();
	for(int  i = 0; group.size() > i ; i++)
	{
		int j = 2;
		group[i]->message = '\0';
		while (j++ < input.size())
		{

			group[i]->message += input[j];//biri vektör diğeri normal string burada sorun çıkıyo seg fault alıyom

		}//bunu halledersek kod okki	
	}*/


	return (0);
}
