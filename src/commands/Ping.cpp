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

	ostringstream oss;
	int fd = user.getFd();
	oss << fd;

	const string strFd = oss.str().c_str();


	Response::create().content(strFd +  " SERVER " + user.getUserName() + " PONG " + user.getNickName() ).send();

	user.message = input[2];
	/*vector<User *> &group = start.getUsers();
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
