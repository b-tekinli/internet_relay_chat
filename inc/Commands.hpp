#ifndef Commands_HPP
#define Commands_HPP

#include <Server.hpp>
#include <DefineMod.hpp>
#include <Message.hpp>
#include <Global.hpp>

typedef int (*fp_command)(const vector<string> &input, Person& user);


namespace cmd
{
	int join(const vector<string> &input, Person& user);
	int kick(const vector<string> &input, Person& user);
	int nick(const vector<string> &input, Person& user);
	int	pass(const vector<string> &input, Person& from);
	int	notice(const vector<string> &input, Person& from);
	int ping(const vector<string> &input, Person& user);
	int pong(const vector<string> &input, Person& user);
	int privmsg(const vector<string> &input, Person& user);
	int quit(const vector<string> &input, Person& user);
	int user(const vector<string> &input, Person &user);
}

bool	isEqual(const string &test, const string &aim, int enter);
void	sendGroup(Person& user, const string n_channel, const string msg);
string	just_text();
bool	find_channel(string target, Person &from);
bool	find_channel(vector <Person*> group, string name);
string	to_str(int	number);
#endif
