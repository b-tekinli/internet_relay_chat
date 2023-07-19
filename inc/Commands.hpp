#ifndef Commands_HPP
#define Commands_HPP

#include "User.hpp"
#include <vector>
#include <unistd.h>

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
