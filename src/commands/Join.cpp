#include <Commands.hpp>

int cmd::join(const vector<string> &input, Person & from)
{
	if (input.size() != 2)
	{
		std::cout << "1. if sea" << std::endl;
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(JOIN_USE).send();
		return (-1);
	}
	if (from.getActive() < HALF)
	{
		std::cout << "2. if sea" << std::endl;
		Response::create().to(from).content(ND_ACTIVE).send();
		return (-1);
	}

	start.addUserTo(input[1], from);
	return (0);
}
