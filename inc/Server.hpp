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
		Server(int new_port, string new_password);
		~Server();

		void			handleInput(int fd, const string &input);
		User			allUser();
		void			setUpSocket();
		vector<User*>	getChannel(const string &channel);
		const string	getPassword() const;


};

/*
User *getUser(int fd);

int saveUser(User user);

int new_user(int fd) {
	users.assign(fd,new User);
}

int new_user(int fd) {
	users.assign(fd,new User);
}*/
#endif