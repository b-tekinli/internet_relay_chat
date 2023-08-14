#ifndef USER_HPP
#define USER_HPP

#include "DefineMod.hpp"

enum e_active
{
	FALSE = 0,
	HALF = 1,
	U_HALF = 2,
	ACTIVE = 3
};

class User
{
	private:
		string			user_name;
		string			host_name;
		string			serv_name;
		string			real_name;
		string			nick_name;
		int				grade;
		int				fd;
		e_active		active;
		bool			oper;
		vector<string>	wh_op;
	public:
		User();
		User(int fd);
		User(const User &user);
		~User();

		User& 			operator=(const User &user);
		vector<string>&	getWhichChannel();
		const string&	getUserName() const;
		const string&	getHostName() const;
		const string&	getServName() const;
		const string&	getRealName() const;
		const string&	getNickName() const;
		const int		getActive() const;
		const bool		getOper() const;
		const int		getFd() const;
		void			setActive(e_active choose);
		void			setUserName(const string& set);
		void			setHostName(const string& set);
		void			setServName(const string& set);
		void			setRealName(const string& set);
		void			setNickName(const string& set);
		void			setOper(bool ch);
		void			addOperator(const string &str);
		void			delOperator(const string str);
		string			message;

};

#endif
