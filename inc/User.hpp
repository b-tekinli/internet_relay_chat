#ifndef USER_HPP
#define USER_HPP

#include "DefineMod.hpp"

enum e_active
{
	FALSE = 0,
	HALF = 1,
	ACTIVE = 2
};

class User
{
	private:
		string		user_name;
		string		host_name;
		string		serv_name;
		string		real_name;
		string		nick_n ame;
		int			grade;
		int			fd;
		e_active	active;
		bool		oper;

	public:
		User();
		User(int fd);
		User(const User &user);
		~User();

		User& 			operator=(const User &user);
		const string&	getUserName() const;
		const string&	getHostName() const;
		const string&	getServName() const;
		const string&	getRealName() const;
		const string&	getNickName() const;
		const int		getActive() const;
		const int		getFd() const;
		void			setActive(e_active choose);
		void			setUserName(const string& set);
		void			setHostName(const string& set);
		void			setServName(const string& set);
		void			setRealName(const string& set);
		void			setNickName(const string& set);
};

#endif
