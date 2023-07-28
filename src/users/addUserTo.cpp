#include <Commands.hpp>

void users::addUserTo(const string &group, User &user, map< string, vector<User*> > &channels)
{
	channels[group].push_back((User *)&user);
}
