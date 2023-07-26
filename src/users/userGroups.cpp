#include <User.hpp>

void users::addUserTo(const string &group, const User &user, map<string, vector<User *> > &channels){
	channels[group].push_back((User *)&user);
}

void users::removeUserFrom(const string &group, const User &user, map<string, vector<User *> > &channels){
	int fd = user.getFd();
	delete channels[group][fd];
	channels[group][fd] = NULL;

}