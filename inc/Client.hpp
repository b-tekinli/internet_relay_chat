#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <DefineMod.hpp>
#include <Global.hpp>
#include <Response.hpp>

class Client {
	public:
		string	get_nickname() const;
		void	push_to_buffer(const string& message);
}

#endif
