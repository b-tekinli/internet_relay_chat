#include "../inc/User.hpp"

User::User()
{

}

User::User(int fd): fd(fd), active(FALSE), oper(false)
{
	stringstream convert;

	convert << fd;
	user_name = "kvirc" + convert.str();
	host_name = user_name;
	serv_name = user_name;
	real_name = user_name;
}

User::User(const User &user)
{

}

User::~User()
{

}

User&			User::operator=(const User &user)
{
	return (*this);
}

const string&	User::getUserName() const
{
	return (user_name);
}

const string&	User::getHostName() const
{
	return (host_name);
}

const string&	User::getServName() const
{
	return (serv_name);
}

const string&	User::getRealName() const
{
	return (real_name);	
}

const string&	User::getNickName() const
{
	return (nick_name);
}

const int		User::getActive() const
{
	return (active);
}

void			User::setActive(int choose)   { active = choose; }

void			User::setUserName(const string& set) {string a = set, user_name = a; }

void			User::setHostName(const string& set) { host_name = set; }

void			User::setServName(const string& set) { serv_name = set; }

void			User::setRealName(const string& set) { real_name = set; }

void			User::setNickName(const string& set) { nick_name = set; }
