#include <User.hpp>

void users::addUserTo(const string &group, const User &user, map<string, vector<User *> > &channels){
	channels[group].push_back((User *)&user);
}
