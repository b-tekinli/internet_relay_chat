#include <Person.hpp>
#include <Server.hpp>

Person::Person(): fd(0), active(FALSE) {}

Person::Person(int fd): fd(fd), active(FALSE)
{
	stringstream convert;

	convert << fd;
	this->user_name= "kvirc" + convert.str();
	this->host_name = this->user_name;
	this->serv_name = this->user_name;
	this->real_name = this->user_name;
	this->nick_name = this->user_name;
}

Person::Person(const Person &user) { *this = user; }

Person::~Person() { 
	if (this->getWhichChannel().size() > 0){
		for (vector<string>::size_type i = 0; i < this->getWhichChannel().size(); i++){
			sendGroup(*this, this->getWhichChannel()[i], "QUIT : Disconnected from server");
			start.removeUserFrom(this->getWhichChannel()[i],*this);
		}
	}
	close(fd);
 }

Person &			Person::operator=(const Person &user)
{
	if (this != &user)
	{
		this->user_name = user.user_name;
		this->host_name = user.host_name;
		this->serv_name = user.serv_name;
		this->real_name = user.real_name;
		this->nick_name = user.nick_name;
	}
	return (*this);
}

vector<string> &Person::getWhichChannel() { return (this->wh_op); }

const string&	Person::getUserName() const { return (this->user_name); }

const string &Person::getHostName() const { return (this->host_name); }

const string &Person::getServName() const { return (this->serv_name); }

const string &Person::getRealName() const { return (this->real_name); }

const string &Person::getNickName() const { return (this->nick_name); }

int Person::getActive() const { return (this->active); }

int Person::getFd() const { return (this->fd); }

void			Person::setActive(e_active choose)	 { this->active = choose; }

void			Person::setUserName(const string& set) { this->user_name = set; }

void			Person::setHostName(const string& set) { this->host_name = set; }

void			Person::setServName(const string& set) { this->serv_name = set; }

void			Person::setRealName(const string& set) { this->real_name = set; }

void			Person::setNickName(const string& set) { this->nick_name = set; }

void			Person::addOperator(const string &str) { this->wh_op.push_back(str); }

void			Person::delOperator(const string str) 
{
	int	i = 0;

	for (; i < int(wh_op.size()); i++)
	{
		if (this->wh_op[i] == str)
		{
			this->wh_op.erase(wh_op.begin() + i);
		}
	}
}
