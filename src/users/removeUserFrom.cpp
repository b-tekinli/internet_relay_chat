#include <Commands.hpp>

void users::removeUserFrom(const string &group, User &user, map<string, vector<User *> > &channels){
	int fd = user.getFd();

	delete channels[group][fd];
	channels[group][fd] = NULL;
}
