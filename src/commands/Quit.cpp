#include "../../inc/Commands.hpp"

int cmd::quit(const vector<string> &input, User& user)
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

// void client_disconnect(int client_fd) {

// 	User* user = getFd(client_fd);

// 	if(user != NULL)
// 		for (const string& channel : user->getChannels())
// 		{
// 			removeFrom(user, channel);
// 		}
		

// 	close(client_fd);

// }
