#include <Commands.hpp>

//normal irc de kullanıcı çıkarken nedenini belirtiyorsa bizim bunu da yazdırmamız gerekiyomuş
int cmd::quit(const vector <string> &input, Person &user)
{
	if (input.size() > 1)
	{
		string reason = input[1];
		
	}
	else
	{
		string reason = "QUIT :Gone to have lunch";

		//write(user.getFd(), reason.c_str(), reason.size());
	}
	Response::createMessage().to(user).content("QUIT :Gone to have lunch").send();
	start.deleteUser(user.getFd());
	close(user.getFd());
	return 0;
}