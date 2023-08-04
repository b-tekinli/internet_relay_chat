#include <Commands.hpp>

int cmd::join(const vector<string> &input, User& from)
{
	if (input.size() != 3)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(NOT_ENOUGH).send();
		return (-1);
	}
	if (from.getActive() < HALF)
	{
		Response::create().to(from).content(ND_ACTIVE).send();
		return (-1);
	}
	Response::create().content(input[1] +  " " + from.getNickName() + "!" + from.getUserName() + "@127.0.0.1: Welcome to Channel " + input[1]);
	start.addUserTo(input[1], from);
	return (0);
}
//
// welcome channel message
// if first channel member then we can turn on oper
//