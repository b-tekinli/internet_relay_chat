#include <User.hpp>

void users::removeUserFrom(const string &group, const User &user, map<string, vector<User *> > &channels){
	int fd = user.getFd();
	delete channels[group][fd];
	channels[group][fd] = NULL;

}
