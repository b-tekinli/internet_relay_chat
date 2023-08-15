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
		map < string, vector<Person*> >	channels;
		vector <Person*>				users;
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
		map< string, vector<Person*> >	&getChannels();
		vector<Person*>					&getUsers();
		Person*							getUserNick(string nick);
		vector<Person*>					&getChannel(const string &channel);
		string							&getRawString();
		void							setRawString(string set);
		/// @brief gets user from list or creates new one and inserts into the list
		/// @param fd 
		/// @return User in the system
		Person*	getOrCreateUser(int fd);
		void	deleteUser(int fd);
		void	addUserTo(const string &group, Person &user);
		void	removeUserFrom(const string &group, Person &user);
};

extern Server start;

#endif