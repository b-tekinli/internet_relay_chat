#ifndef Commands_HPP
#define Commands_HPP

#include <Server.hpp>
#include <DefineMod.hpp>
#include <Message.hpp>
#include <Global.hpp>

typedef int (*fp_command)(const vector<string> &input, User& user);


namespace cmd
{
	int join(const vector<string> &input, User& user);
	int kick(const vector<string> &input, User& user);
	int nick(const vector<string> &input, User& user);
	int list(const vector<string> &input, User &user);
	int	pass(const vector<string> &input, User& from);
	int	notice(const vector<string> &input, User& from);
	int ping(const vector<string> &input, User& user);
	int pong(const vector<string> &input, User& user);
	int privmsg(const vector<string> &input, User& user);
	int quit(const vector<string> &input, User& user);
	int user(const vector<string> &input, User &user);
}

bool	isEqual(const string &test, const string &aim, int enter);
void	sendGroup(User& user, const string n_channel, const string msg);
string	just_text();
bool	find_channel(string target, User &from);
bool	find_channel(vector <User*> group, string name);
#endif
