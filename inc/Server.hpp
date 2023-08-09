#ifndef SERVER_HPP
#define SERVER_HPP

#include <DefineMod.hpp>
#include <Global.hpp>
#include <Response.hpp>

class Server
{
	private:
		int								port;
		string							password;
		map < string, vector<User*> >	channels;
		vector <User*>					users;
		string							raw_string;
	public:
		Server();
		~Server();
		void							toBegin();
		void							handleInput(int fd, const string &input);
		void							setUpSocket();
		const string					getPassword() const;	
		void							setPort(int port);
		void							setPassword(string pass);
		map< string, vector<User*> >	&getChannels();
		vector<User*>					&getUsers();
		User*							getUserNick(string nick);
		vector<User*>					&getChannel(const string &channel);
		string							&getRawString();
		void							setRawString(string set);
		/// @brief gets user from list or creates new one and inserts into the list
		/// @param fd 
		/// @return User in the system
		User*	getOrCreateUser(int fd);
		void	deleteUser(int fd);
		void	addUserTo(const string &group, User &user);
		void	removeUserFrom(const string &group, User &user);
};

extern Server start;

#endif