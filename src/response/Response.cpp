#include <Response.hpp>
#include <iostream>
#include <cstdlib>


/// @brief  generated response :<prefix> <number>
/// @param reply 
/// @param target 
/// @param content 
/// @return 
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
