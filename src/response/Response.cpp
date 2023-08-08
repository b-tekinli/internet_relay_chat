#include <Response.hpp>
#include <Commands.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>

/// @brief  generated response :<prefix> <number>
/// @param reply 
/// @param target 
/// @param content 
/// @return 
const std::string generateReply(Reply reply, const User &target, const std::string &content){
	std::string message = "";
	char reply_str[4];
	sprintf(reply_str,"%d",reply);
	message += ":<hostname>"; //TODO: implement prefix generator
	message += " ";
	message += reply_str;
	message += " ";
	message += target.getNickName();
	message += " :";
	message += content;

	return message;
}

Response::Response(){
	this->mFrom = "Server";
	this->mCode = NONE;
	this->mTo = "anonymous!anonymous@anonymous";
	this->mContent = "No Content.";
	this->mFd = 1;
}

Response::Response(const Response &response) {
	*this = response;
}

Response& Response::operator=(const Response &response){
	mFrom = response.mFrom;
	mTo = response.mTo;
	mFd = response.mFd;
	mCode = response.mCode;
	mContent = response.mContent;
	return *this;
}

Response::~Response(){}

Response Response::create()
{
	Response response;
	return response;
}

Response Response::withCode(const Reply &reply)
{
	Response response;
	response.mCode = reply;
	return response;
}

Response& Response::from(const User &from) { 
	mFrom = from.getNickName();
	return *this;
 }

Response& Response::to(const User &user) {
	mFd = user.getFd();
	mTo = user.getNickName();
	return *this;
}

Response& Response::code(const Reply &reply) {
	mCode = reply;
	return *this;
}

Response& Response::content(const string &content){
	mContent = content;
	return *this;
}


//TODO: generalize responses
/// General stucture of responses: ":"
void Response::send(){
	std::stringstream stream;
	string message;
	
	stream << ":" << mFrom << " "; // prefix
	stream << std::setw(3) << std::setfill('0') << mCode << " "; // 3 digit numeric Code
	stream << mTo; // Target
	stream << " :" << mContent << endl; // Content
	
	message = stream.str();
	write(mFd, message.c_str(), message.length());
}

