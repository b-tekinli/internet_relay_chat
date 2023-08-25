#ifndef	UTILS_HPP
#define	UTILS_HPP

#include <Server.hpp>
#include <Message.hpp>
#include <DefineMod.hpp>
#include <Global.hpp>
#include <DefineMod.hpp>

#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define DEFAULT "\033[0m"

void	sendModeNotice(vector<Person *> &channel, string group, string nickname);
void	sendGroup(Person & user, const string n_channel, const string msg);
void	printClient(string msg, Person &server);
void	printServer(string msg);
bool	find_channel(string target, Person &from);
bool	find_channel(vector <Person *> group, string name);
bool	isEqual(const string &test, const string &aim, int enter);
string	showInChannelNames(vector<Person *>& persons);
string	to_str(int	number);
string	getColor(int fd);
string	getTime();



#endif