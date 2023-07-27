#ifndef REPLY_HPP
#define REPLY_HPP
#include <string>

enum Reply {
	RPL_WELCOME = 1,
	RPL_YOURHOST = 2,
	RPL_CREATED = 3,
	RPL_MYINFO = 4,
	RPL_BOUNCE = 5,
	ERR_NOSUCHNICK = 401,
};

typedef enum Reply Reply;

const std::string generateReply(Reply reply);
#endif