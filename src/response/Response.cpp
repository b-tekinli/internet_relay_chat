#include <Response.hpp>
#include <Commands.hpp>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
#include <arpa/inet.h>
#include <netdb.h>

/*
static string getServerHostName()
{
	struct addrinfo hints = { 0 };
	struct addrinfo *res;
	char address[INET_ADDRSTRLEN];
	char host[] = "localhost";
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_CANONNAME;

	if (getaddrinfo(host,NULL,&hints,&res) == 0){
		inet_ntop(res->ai_family, &((struct sockaddr_in *)res->ai_addr)->sin_addr, address, INET_ADDRSTRLEN);
		freeaddrinfo(res);
		return string(address);
	}
	else return "Undefined";
	return string(address);
}*/

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
		stream << ":" << mFrom << " "; // prefix
	stream << mContent;
	stream << mContentExtra.str() << "\r\n";
	return stream.str();
}

string Response::generateReply(){
	std::stringstream stream;

	stream << ":" << mFrom << " "; // prefix
	stream << std::setw(3) << std::setfill('0') << mCode << " "; // 3 digit numeric Code
	stream << mTo; // Target
	if (!mContent.empty())
		stream << " :" << mContent;
	stream << mContentExtra.str() << "\r\n";
	return stream.str();
}

//TODO: generalize responses
/// General stucture of responses: ":"
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
	
	cout << "this is message =" << message << endl;
	::send(mFd, message.c_str(), message.length(),0);
}

// "PRIVMSG kaan :Merhaba Kaan"
int sendUser(const Person *origin, const Person &target, const string &message){
	string buffer = "";
	if (origin != NULL){
		buffer = ":" + origin->getNickName() + "!" + origin->getUserName() + "@" + origin->getServName();
	}
	buffer += " ";
	buffer += message;

	return write(target.getFd(), buffer.c_str(), buffer.length());
}
