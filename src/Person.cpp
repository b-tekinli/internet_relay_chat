#include <Person.hpp>

Person::Person(): fd(0), active(FALSE) {}

Person::Person(int fd): fd(fd), active(FALSE)
{
	stringstream convert;

	convert << fd;
	this->user_name= "kvirc" + convert.str();
	this->host_name = this->user_name;
	this->serv_name = this->user_name;
	this->real_name = this->user_name;
	this->nick_name = " ";
}

Person::Person(const Person &user) { *this = user; }

Person::~Person() { cout << "Destructor is work" << endl; }

Person &			Person::operator=(const Person &user)
{
	if (this != &user)
	{
		this->user_name = user.user_name;
		this->host_name = user.host_name;
		this->serv_name = user.serv_name;
		this->real_name = user.real_name;
		this->nick_name = " ";
	}
	return (*this);
}

vector<string>&	Person::getWhichChannel() { return (wh_op); }

const string&	Person::getUserName() const { return (user_name); }

const string&	Person::getHostName() const { return (host_name); }

const string&	Person::getServName() const { return (serv_name); }

const string&	Person::getRealName() const { return (real_name);	}

const string&	Person::getNickName() const { return (nick_name); }

const int		Person::getActive() const { return (active); }

const int		Person::getFd() const { return (fd); }

void			Person::setActive(e_active choose)	 { active = choose; }

void			Person::setUserName(const string& set) { user_name = set; }

void			Person::setHostName(const string& set) { host_name = set; }

void			Person::setServName(const string& set) { serv_name = set; }

void			Person::setRealName(const string& set) { real_name = set; }

void			Person::setNickName(const string& set) { nick_name = set; }

void			Person::addOperator(const string &str) { wh_op.push_back(str); }

void			Person::delOperator(const string str) 
{
	int	i = 0;

	for (; i < wh_op.size(); i++)
	{
		if (wh_op[i] == str)
		{
			wh_op.erase(wh_op.begin() + i);
		}
	}
}
