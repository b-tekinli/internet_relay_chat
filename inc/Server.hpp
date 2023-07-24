#ifndef SERVER_HPP
#define SERVER_HPP

#include "Global.hpp"

class Server
{
	private:
		int					port;
		string				password;
		multimap <string, User>	group;
		map <int, User>		all_user;
	public:
		Server(int new_port, string new_password);
		~Server();

		void    setUpSocket();
		void	handleInput(int fd, const string &input);
};

#endif