#ifndef Commands_HPP
#define Commands_HPP

#include <Server.hpp>
#include <DefineMod.hpp>
#include <Message.hpp>

typedef int (*fp_command)(const vector<string> &input, User& user);


namespace cmd
{
	int join(const vector<string> &input, User& user);
	int nick(const vector<string> &input, User& user);
	int quit(const vector<string> &input, User& user);
	int kick(const vector<string> &input, User& user);
	int ping(const vector<string> &input, User& user);
	int pong(const vector<string> &input, User& user);
	int	who(const  vector<string> &input, User& user);
	int user(const vector<string> &input, User &user);
	int mode(const vector<string> &input, User &user);
	int	pass(const vector<string> &input, User& from);
	int	part(const vector<string> &input, User& user);
	int list(const vector<string> &input, User &user);
	int	notice(const vector<string> &input, User& from);
	int privmsg(const vector<string> &input, User& user);
}

bool	isEqual(const string &test, const string &aim, int enter);
void	sendGroup(const User& user, string n_channel, string msg);
string	str_merge(const vector<string> &input);
bool	find_channel(string target, User &from);
#endif
