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
		map <int, User>					all_user;
		vector < User *>				all_user_vec;
	public:
		Server(int new_port, string new_password);
		~Server();

		void			setUpSocket();
		void			handleInput(int fd, const string &input);
		vector<User*>	getChannel(const string &channel);
		User	allUser();
};


User *getUser(int fd);

int saveUser(User user);

int new_user(int fd) {
	all_user.assign(fd,new User);
}

int new_user(int fd) {
	all_user.assign(fd,new User);
}
#endif