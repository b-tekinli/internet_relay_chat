#ifndef SERVER_HPP
#define SERVER_HPP

#include "DefineMod.hpp"
#include "Global.hpp"

class Server
{
	private:
		static	Server					*single_instance;
		int								port;
		string							password;
		map < string, vector<User*> >	group;
		vector <User*>					users;
	public:
		Server();
		Server(int new_port, string new_password);
		////Server(const Server &server);
		////Server& operator=(const Server &server);
		~Server();
		static void		init_server(int new_port, string new_password);
		static Server&	getInstance();
		void			handleInput(int fd, const string &input);
		User			allUser();
		void			setUpSocket();
		vector<User*>	getChannel(const string &channel);
		const string	getPassword() const;


};


#endif