#include <Server.hpp>

Server	start;

bool	control(char **av)
{
	int port = atoi(av[1]);

	if (port >= 1024 && port <= 65535)
		return true;
	return false;
}

int	main(int ac, char **av)
{
	if (ac != 3 || !control(av))
	{
		cout << "You have entered the missing argument!" << endl;
		cout << "./irc <port> <password>" << endl;
		return (1);
	}
	start.setPort(atoi(av[1]));
	start.setPassword(av[2]);
	start.toBegin();
	return (0);
}
