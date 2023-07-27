#include "../../inc/Server.hpp"
#include "../../inc/Commands.hpp"


bool    isEqual(const string &test, const string &aim, int enter)
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

/**
 * selcommand used for select command for given input
 * @param input: Input string
 * @return fp_command is the type of the function that represents 
 */
fp_command selCommand(vector<string> &input)
{
	string		str[] = {"JOIN", "NICK", "QUIT", "KILL", "PING", "PONG", "WHO", "USER", "PASS"};
	fp_command	result[] = {cmd::join, cmd::nick, cmd::quit, cmd::kill, cmd::ping, cmd::pong, cmd::who, cmd::user, cmd::pass, NULL};
	int			i;

	for (i = -1; i < 9; ++i)
        if (isEqual(input[0], str[i], input.size() >= 1) || 
                isEqual(input[1], str[i], input.size() >= 2))
            break;
    return result[i];
}


/// @brief handles input
/// @param fd 
/// @param input 
void	Server::handleInput(int fd, const string &input)
{
	//User user = getOrCreateUser(fd);
    fp_command 		func;
    string			str;
    stringstream	sstream(input);
    vector<string>	commands;

    while (getline(sstream, str, ' '))
    {
        if (str[0] > 33)
            commands.push_back(str);
    }
	// [<prefix>] <numeric_code> <param1> <param2>
	write(fd,"001 amy :Ahmet naber\n",100);
    cout << "not enter : " << fd << endl;
    //// create command from input
	if (commands.size() >= 2 && (func = selCommand(commands)) != 0)
        func(commands, *users[fd]);
    else
    {
        write(fd," 001 amy :Welcome to the Internet Relay Network borja!borja@polaris.cs.uchicago.edu\n",100); //return come of the text to the client
    }
}

// const string& generateReply(int code, User, string message);

void    Server::setUpSocket()
{
    Socket clientSocket;
    vector<struct pollfd> pollfds;

    clientSocket.init(port);
    pollfds.push_back( (struct pollfd){clientSocket.getSocketFd(), POLLIN, 0} );
    cout << pollfds[0].fd << endl;
    cout << clientSocket.getSocketFd() << endl;
    cout << pollfds.size() << endl;
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
                    cout << "SEE_fd = " << clientFd << endl;
                    cout << "SEE_pollfd = " << pollfds[clientFd].fd << endl;
                    cout << HALF << FALSE << ACTIVE << endl;
                    users[clientFd] = &person;
                }
                else // Connected to client
                {
                    char input[512] = {0};
                    int	readed = recv(pollfds[i].fd, input, sizeof(input) - 1,  0);

					if (readed <= 1) // user_close
						close(pollfds[i].fd);
					handleInput(pollfds[i].fd, string(input));
				}
            }
        }
    }
	exit (0);
}
