#include <response.hpp>
#include <iostream>
#include <cstdlib>



const std::string generateReply(Reply reply,std::string params[]){
	std::string message = "";
	message += ":prefix"; //TODO: implement prefix generator
	message += " ";
	message += std::to_string(reply);
	

	return message;
}
