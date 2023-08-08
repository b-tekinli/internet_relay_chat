#ifndef MESSAGE_HPP
#define MESSAGE_HPP

//error
#define WR_PASS			"Incorrect Password "
#define NO_PASS			"Your Connections Is Restricted "
#define CH_NAME			"Channel name fist characther must be '#' "
#define NOT_ENOUGH		"Not enough parameters "
#define ND_ACTIVE		"You need to be active "
#define A_REGIST		"Unauthorized command "
#define NO_SUCH			"No such nick/channel "
#define NO_MEM			"You are not a memeber this channel => "
#define NO_OPER			" :You're not on that channel "
#define NO_CHANNEL		" :No such channel"

#define KICK_TO			"Kick by the operator"
#define ER_NICK_USED	" :Nickname is already in use"
#define ER_ALREADY_JOIN	"Error: You already joined this channel"
#define FIRST_USERSET	"Error: First you have to set user setting"

//not enough param
#define KICK_USE	"KICK usage 'KICK <channel> <user>'"
#define JOIN_USE	"JOIN usage 'JOIN #<channel>'"
#define NICK_USE	"NICK usage 'NICK <nick name>"
#define NOTICE_USE	"NOTICE usage 'NOTICE <target> <text>'"
#define PASS_USE	"PASS usage 'PASS <password>'"
#define PRIVMSG_USE	"PRIVMSG usage 'PRIVMSG <target> <text>'"
#define USER_USE	"USER usage 'USER <user name> <host name> <serv name> <real name>'"

//success
#define WELCOME			"Welcome to the Internet Relay Network "
#define CORRECT_PASS	"Password is correct"
#define INCORRECT_PASS	"Incorrect Password!"

#endif
