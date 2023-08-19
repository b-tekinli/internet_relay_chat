#ifndef REPLY_HPP
#define REPLY_HPP
#include <string>
#include <Person.hpp>

enum Reply
{
	/// @brief Represents no code. Pass it when you don't want to give a code number
	NONE=0,
	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_WELCOME = 1,

	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_YOURHOST = 2,

	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_CREATED = 3,

	/// @brief The server sends Replies 001 to 004 to a user upon successful registration
	RPL_MYINFO = 4,

	/// @brief Info message
	RPL_INFO = 371,
	RPL_BOUNCE = 5,
	RPL_TOPIC = 332,
	RPL_NOTOPIC = 331,
	RPL_AWAY = 301,
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
	ERR_TOOMANYTARGETS = 407,
	ERR_PASSWDMISMATCH = 464,
	ERR_UNKNOWNCOMMAND = 421,
	ERR_USERONCHANNEL = 443

};

enum ResponseType {
	REPLY,
	MESSAGE,
	SET
};

/// @brief Response class (Chain of responsibility)
class Response {
	private:
		ResponseType responseType;
		string mFrom;
		string mTo;
		int mFd;
		Reply mCode;
		string mContent;
		stringstream mContentExtra;
		string generateMessage();
		string generateReply();
	public:

		Response();

		Response(const Response& response);

		~Response();

		Response& operator=(const Response& response);

		/// @deprecated You should use other constructors to instantiate Response object
		/// @brief [DEPRECATED!] Creates a Response instance default mode. (It's deprecated. Use Response::createMessage() or Response::createReply() instead)
		/// @return Response instance that represents replies
		static Response create();

		/// @deprecated You should use other constructors (Response::createReply(Reply)) to instantiate Response object
		/// @brief [DEPRECATED!] Creates a Response instance default mode. (It's deprecated. Use Response::createReply() instead)
		/// @return Response instance that represents replies
		static Response withCode(const Reply &reply);

		/// @brief Creates a Response instance to send messages
		/// @example Response::createMessage().from(origin).to(target).addContent(message).send();
		/// @return Response instance that represents messages
		static Response createMessage();

		/// @brief Creates a Response instance to send replies
		/// @param reply RPL code or ERR code that will be send to client
		/// @example Response::createReply(RPL_WELCOME).to(target).content("Welcome!").send();
		/// @return Response instance that represents replies
		static Response createReply(const Reply &reply);		

		/// @brief Sets the origin of response. Do not call if you want to set server as origin.
		/// @param Person: Origin of the response
		/// @return Returns itself for chaining methods.
		Response& from(const Person &from);
		
		/// @brief Sets the target of the response. The response will be send to this target
		/// @param user The target of the response
		/// @return Returns itself for chaining methods.
		Response& to(const Person & user);
		
		/// @brief Sets numeric code of the response. You should use this if the type of response is REPLY
		/// @param reply 
		/// @return Returns itself for chaining methods.
		Response& code(const Reply &reply);
		
		/// @brief Sets content of response
		/// @param string Content of the response
		/// @return Returns itself for chaining methods.
		Response& content(const string &content);
		
		/// @brief Adds extra content for response
		/// @param string Content of the response
		/// @return Returns itself for chaining methods.
		Response& addContent(const string &content);

		/// @brief Sends response to the target. To specify target, use .to(user) function
		void send();
};

/// @deprecated Use Response::createMessage() instead
int sendUser(const Person *origin, const Person &target, const std::string &message);

#endif