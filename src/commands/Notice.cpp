#include <Commands.hpp>

int cmd::notice(const vector<string> &input, User& from)
{
	if (input.size() != 3)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(NOTICE_USE).send();
		return (-1);
	}
	string	msg = str_merge(input);

	sendGroup(from, input[1], msg);
	return (0);
}
 