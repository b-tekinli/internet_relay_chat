#include <Commands.hpp>

 int cmd::part(const vector<string> &input, User& user)
 {
 	
	if (user.getActive() != ACTIVE){
		Response::withCode(ERR_NOTREGISTERED).to(user).content("You must register to the server").send();
		return -1;
	}

 	return (0);
 }
