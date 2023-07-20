#ifndef USER_HPP
#define USER_HPP

#include "DefineMod.hpp"

class User
{
	private:
		string user_name;
		string host_name;
		string serv_name;
		string real_name;
		string nick_name;
		int grade;
	public:
		User();
		User(string user_name, string host_name, string serv_name, string real_name, string nick_name);
		User(const User &user);
		~User();
		User& operator=(const User &user);
		const string& getUserName() const;
		const string& getHostName() const;
		const string& getServName() const;
		const string& getRealName() const;
		const string& getNickName() const;
};

#endif
