#include <Response.hpp>
#include <iostream>
#include <cstdlib>



const std::string generateReply(Reply reply, const User &target, const std::string &content){
	std::string message = "";
	
	message += ":<hostname>"; //TODO: implement prefix generator
	message += " ";
	message += std::to_string(reply);
	message += " ";
	message += target.getNickName();
	message += " :";
	message += content;

	return message;
}
