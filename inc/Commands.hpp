#ifndef Commands_HPP
#define Commands_HPP

#include <Server.hpp>
#include <Message.hpp>
#include <DefineMod.hpp>
#include <Global.hpp>
#include <Utils.hpp>

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

#endif
