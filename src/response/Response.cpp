#include <Response.hpp>
#include <Commands.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <arpa/inet.h>
#include <netdb.h>

Response::Response()
{
	this->mFrom = start.getHostname();
	this->mCode = NONE;
	this->mTo = "";
	this->mContent = "";
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
	response.responseType = REPLY;
	return response;
}

Response Response::createMessage()
{
	Response response;
	response.responseType = MESSAGE;
	return response;
}

Response Response::withCode(const Reply &reply)
{
	Response response;
	response.mCode = reply;
	response.responseType = REPLY;
	return response;
}

Response Response::createReply(const Reply &reply)
{
	Response response;
	response.mCode = reply;
	response.responseType = REPLY;
	return response;
}

Response& Response::from(const Person &from) { 
	mFrom = from.getNickName() + "!" + from.getUserName() + "@" + from.getHostName();
	return *this;
 }

Response& Response::to(const Person &user) {
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

Response& Response::addContent(const string &content){
	if (!content.empty())
		mContentExtra << " " << content;
	else
		mContentExtra << "";
	return *this;
}

string Response::generateMessage(){
	std::stringstream stream;

	if (!mFrom.empty())
		stream << ":" << mFrom << " ";
	stream << mContent;
	stream << mContentExtra.str() << "\r\n";
	return stream.str();
}

string Response::generateReply(){
	std::stringstream stream;

	stream << ":" << mFrom << " ";
	stream << std::setw(3) << std::setfill('0') << mCode << " ";
	stream << mTo;
	if (!mContent.empty())
		stream << " :" << mContent;
	stream << mContentExtra.str() << "\r\n";
	return stream.str();
}

void Response::send(){
	std::stringstream stream;
	string message;
	switch(this->responseType){
		case MESSAGE:
			message = generateMessage();
			break;
		case REPLY:
			message = generateReply();
			break;
	}
	::send(mFd, message.c_str(), message.length(), 0);
}

int sendUser(const Person *origin, const Person &target, const string &message){
	string buffer = "";
	if (origin != NULL){
		buffer = ":" + origin->getNickName() + "!" + origin->getUserName() + "@" + origin->getServName();
	}
	buffer += " ";
	buffer += message;
	return write(target.getFd(), buffer.c_str(), buffer.length());
}
