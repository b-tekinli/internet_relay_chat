#ifndef REPLY_HPP
#define REPLY_HPP
#include <string>
#include <User.hpp>

enum Reply
{
	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_WELCOME = 1,

	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_YOURHOST = 2,

	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_CREATED = 3,

	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_MYINFO = 4,
	RPL_BOUNCE = 5,
	RPL_TOPIC = 332,
	RPL_AWAY = 301,
	RPL_LISTSTART = 321,
	RPL_LIST = 322,
	RPL_LISTEND = 323,
	RPL_WHOREPLY = 352,
	RPL_ENDOFWHO = 315,
	ERR_NOSUCHNICK = 401,
	ERR_NEEDMOREPARAMS = 461,
	ERR_BANNEDFROMCHAN = 474,
	ERR_INVITEONLYCHAN = 473,
	ERR_BADCHANNELKEY = 475,
	ERR_CHANNELISFULL = 471,
	ERR_BADCHANMASK = 476,
	ERR_NOTREGISTERED = 451,
	ERR_TOOMANYCHANNELS = 405,
	ERR_NOSUCHCHANNEL = 403,
	ERR_CHANOPRIVSNEEDED = 482,
	ERR_USERNOTINCHANNEL = 441,
	ERR_NOTONCHANNEL = 442,
	ERR_NONICKNAMEGIVEN = 431,
	ERR_ERRONEUSNICKNAME = 432,
	ERR_NICKNAMEINUSE = 433,
	ERR_NICKCOLLISION = 436,
	ERR_UNAVAILRESOURCE = 437,
	ERR_RESTRICTED = 484,
	ERR_ALREADYREGISTRED = 462,
	ERR_NOORIGIN = 409,
	ERR_NOSUCHSERVER = 402,
	ERR_NORECIPIENT = 411,
	ERR_NOTEXTTOSEND = 412,
	ERR_CANNOTSENDTOCHAN = 404,
	ERR_NOTOPLEVEL = 413,
	ERR_WILDTOPLEVEL = 414,
	ERR_TOOMANYTARGETS = 407

};

/// @brief Response class (Chain of responsibility)
class Response {
	private:
		string mFrom;
		string mTo;
		int mFd;
		Reply mCode;
		string mContent;
	public:

		Response();
		Response(const Response& response);
		~Response();
		Response& operator=(const Response& response);
		static Response create();
		static Response withCode(const Reply &reply);
		Response& from(const User &from);
		Response& to(const User& user);
		Response& code(const Reply &reply);
		Response& content(const string &content);
		void send();
};


const std::string generateReply(Reply reply, const User &target, const std::string &content);
#endif