#include <Commands.hpp>


int cmd::pass(const vector<string> &input, User& from)
{
	if (input.size() < 2)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(input[0] + NOT_ENOUGH).send();
		return (-1);
	}
	else if (from.getActive() != FALSE)
	{
		Response::create().to(from).code(ERR_ALREADYREGISTRED).content(A_REGIST).send();
		return (-1);
	}
	if (isEqual(input[1], start.getPassword(), 1))
	{
		from.setActive(HALF);
		Response::create().to(from).content("Password is correct\n").send();
		cout << "correct" << endl;
		return (1);
	}
	else
		Response::create().to(from).content("Incorrect Password!\n").send();
	return (0);
}
