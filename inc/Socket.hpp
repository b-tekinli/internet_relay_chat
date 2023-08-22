#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <Person.hpp>
#include <DefineMod.hpp>

class Socket
{
	private:
		int			fd_socket;
		sockaddr_in	connect_int;

	public:
		Socket();
		~Socket();

		bool	init(int por);
		bool	Create(int port);
		bool	Bind();
		bool	Listen();
		int		Accept();
		void	Close();

		int	 getSocketFd();
};

#endif
