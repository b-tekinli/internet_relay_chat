#include <../inc/Socket.hpp>



Socket::Socket() : fd_socket(0) {}

Socket::~Socket() { Close(); }

bool Socket::Create(int port)
{
	int opt = 1;

	fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_socket == -1)
	{
		perror("Socket function doesn't work");
		exit (EXIT_FAILURE);
	}
	else if (setsockopt(fd_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	connect_int.sin_family = AF_INET;
	connect_int.sin_addr.s_addr = INADDR_ANY;
	connect_int.sin_port = htons(port);
	return (fd_socket != -1);
}

bool Socket::Bind()
{
	return (bind(fd_socket, (struct sockaddr *)&connect_int, sizeof(connect_int)) != -1);
}

bool Socket::Listen()
{
	return (listen(fd_socket, MAX_CLIENT) != -1);
}

int Socket::Accept()
{
	socklen_t	clientSize = sizeof(connect_int);
	int			fd = accept(fd_socket, (struct sockaddr *)&connect_int, (socklen_t *)&clientSize);
	return (fd);
}

bool Socket::init(int port)
{
	Create(port);
	if (getSocketFd() < 0)
	{
		cout << "Cannot open the socket file " << endl;
		return false;
	}
	Bind();
	Listen();
	return true;
}

void Socket::Close()
{
	if (fd_socket != 0)
	{
		close(fd_socket);
		fd_socket = 0;
	}
}

int Socket::getSocketFd() { return (this->fd_socket); }
