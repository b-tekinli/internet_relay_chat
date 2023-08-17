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

/*
//beyza hocamızın denedigi
int cmd::quit(const vector<string> &input, Person & user)
{
	// string text;

	// if(input.size() > 1) 
	// {
	// 	text = just_text();
	// }
	// else
	// {
	// 	text = "Leaving"; //close fd vector sil ve 
	// }

	// client->send("QUIT " + text);
	// sw->client_disconnect(client->get_fd());

	cout << "quit" << endl;
	return (0);
}

*/

// void client_disconnect(int client_fd) {

// 	Person * user = getFd(client_fd);

// 	if(user != NULL)
// 		for (const string& channel : user->getChannels())
// 		{
// 			removeFrom(user, channel);
// 		}
		

// 	close(client_fd);

// }
