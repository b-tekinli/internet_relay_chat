#include <Commands.hpp>

static string join_input(const vector<string> &input) {
	string str = "";
	for (int i = 2; i < input.size(); i++){
		str += input[i] + " ";
	}
	return str;
}

int cmd::notice(const vector<string> &input, Person & from)
{
	if (input.size() < 3)
	{
		Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(NOTICE_USE).send();
		return (-1);
	}
	else if (input[2].find("LAGCHECK") != std::string::npos)
		return (-1);
	Response::createMessage().from(from).to(from).content("NOTICE").addContent(input[1] + " :" + join_input(input)).send(); // you can fix message
	return (0);
}
 