#include <Commands.hpp>

int cmd::pass(const vector<string> &input, Person & from)
{
	if (input.size() != 2)
	{
		Response::withCode(ERR_NEEDMOREPARAMS).to(from).content(PASS_USE).send();
		return (-1);
	}
	else if (from.getActive() != FALSE)
	{
		Response::withCode(ERR_ALREADYREGISTRED).to(from).content(A_REGIST).send();
		return (-1);
	}
	else if (!isEqual(start.getPassword(), input[1], 1))
	{
		Response::withCode(ERR_PASSWDMISMATCH).to(from).content(INCORRECT_PASS).send();
		return (-1);
	}
	else if (isEqual(start.getPassword(), input[1], 1))
	{
		from.setActive(HALF);
		Response::withCode(RPL_INFO).to(from).content(CORRECT_PASS).send();
		return (-1);
	}
	return (0);
}
