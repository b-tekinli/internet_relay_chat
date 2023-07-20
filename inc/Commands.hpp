#ifndef Commands_HPP
#define Commands_HPP

#include "DefineMod.hpp"
#include "User.hpp"

typedef int (*fp_command)(const vector<string> &input, const User &user);

namespace cmd
{
	int join(const vector<string> &input, const User &user);
	int nick(const vector<string> &input, const User &user);
	int quit(const vector<string> &input, const User &user);
	int kill(const vector<string> &input, const User &user);
	int ping(const vector<string> &input, const User &user);
	int pong(const vector<string> &input, const User &user);
	int	who(const vector<string> &input, const User &user);
	int	user(const vector<string> &input, const User &user);
	int	pass(const vector<string> &input, const User &user);
}

#endif
