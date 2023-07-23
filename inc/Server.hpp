#ifndef SERVER_HPP
#define SERVER_HPP

#include "Global.hpp"

class Server
{
	private:
		int&				port;
		string&				password;
		map <string, User>	group;
		vector<User>		all_user;
	public:
		Server(int port, string password);
		~Server();

		void    setUpSocket();
		void	handleInput(int fd, const string &input);
};

#endif