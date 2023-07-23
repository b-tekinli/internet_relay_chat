#include "../../inc/Server.hpp"

bool sameOrNot(string &test, string &aim, int enter)
{
    if (enter == 0)
        return (false);
    int size = aim.size();
    int i;

    for (i = 0; i < size && aim[i] == test[i]; ++i);

    if (size == i)
        return (true);
    return (false);
}

fp_command selCommand(vector<string> &input) //büyük harf olması gerekiyor
{
	string		str[] = {"JOIN", "NICK", "QUIT", "KILL", "PING", "PONG", "WHO", "USER", "PASS"};
	fp_command	result[] = {cmd::join, cmd::nick, cmd::quit, cmd::kill, cmd::ping, cmd::pong, cmd::who, cmd::user, cmd::pass, 0};
	int			i;

	for (i = -1; i < 9; ++i)
        if (sameOrNot(input[0], str[i], input.size() >= 1) || 
                sameOrNot(input[1], str[i], input.size() >= 2))
            break;
    return result[i];
}//l value d value (const)

void	Server::handleInput(int fd, const string &input)
{
    fp_command 		func;
    string			str;
    stringstream	sstream(input);
    vector<string>	commands;

    while (getline(sstream, str, ' ')){
        commands.push_back(str);
    }
    // create command from input
    cout << all_user[fd].getUserName() << endl;
	if (commands.size() >= 2 && (func = selCommand(commands)) != 0)
        func(commands, all_user[fd]);
    else
        cout << "at here" << endl;
	//USERS[fd];
}

void    Server::setUpSocket()
{
    Socket clientSocket;
    vector<struct pollfd> pollfds;

    clientSocket.init(port);
    pollfds.push_back( (struct pollfd){clientSocket.getSocketFd(), POLLIN} );
    while (poll(&pollfds[0], pollfds.size(), -1))
    {
        for (int i = 0; i < pollfds.size(); i++)
        {   
            if(pollfds[i].revents & POLLIN)
            {    
                if (pollfds[i].fd == clientSocket.getSocketFd())// Connected to socket
                {   /**
                    * yeni bir bağlantı oluşturulup oluşturulmadığını kontorl edecek ve eğer yeni
                    * bir bağlantı varsa fonsiyonun içerisine girip acceptleyecek
                    * yeni bağlnatı olduğunu nasıl anlıyor? 
                    */
                    int     clientFd =  clientSocket.Accept();
                    User    person(clientFd);

    				fcntl(clientFd, F_SETFL, O_NONBLOCK);
                    pollfds.push_back( (struct pollfd){clientFd, POLLIN | POLLOUT} );
                    all_user.push_back(person);
                    cout << "New client connected!" << endl;
                }
                else // Connected to client
                {
                    char input[512] = {0};
                    int	readed = recv(pollfds[i].fd, input, sizeof(input) - 1,  0);
					if (readed <= 1)
						close(pollfds[i].fd);
					handleInput(pollfds[i].fd, string(input));
				}
            }
        }
    }
	exit (0);
}
