#ifndef SERVER_HPP
#define SERVER_HPP

#include "DefineMod.hpp"
#include "Global.hpp"

class Server
{
	private:
		int								port;
		string							password;
		map < string, vector<User*> >	group;
		vector <User*>					users;
	public:
		Server();
		~Server();
		void			toBegin();
		void			handleInput(int fd, const string &input);
		void			setUpSocket();
		const string	getPassword() const;
		vector<User*>	getChannel(const string &channel);
		void			setPort(int port);
		void			setPassword(string pass);
};


extern Server start;

#endif