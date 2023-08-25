#include <Commands.hpp>

static string join_input(const vector<string> &input) {
	string str = "";
	for (int i = 2; i < int(input.size()); i++){
		str += input[i] + " ";
	}
	return str;
}

int cmd::notice(const vector<string> &input, Person &origin)
{
	if (input.size() < 3)
	{
		return (-1);
	}
	else if (input[2].find("LAGCHECK") != std::string::npos)
		return (-1);
	if (input[1].c_str()[0] == '#'){
		vector<Person*> users = start.getChannel(input[1]);
		for (int i = 0; i < int(users.size()); i++){
			Person *target = users[i];
			if (target != NULL && target->getNickName() != origin.getNickName())
				Response::createMessage().from(origin).to(*target).content(input[0] + " " + input[1] + " :" + join_input(input)).send();
		}
	}
	else{	
		Person *target = start.getUserNick(input[1]);
		if (target != NULL)
			Response::createMessage().from(origin).to(*target).content(input[0] + " " + input[1] + " :" + join_input(input)).send();
	}
	return (0);
}
 