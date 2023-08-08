#include "../../inc/Server.hpp"
#include "../../inc/Commands.hpp"

bool	isEqual(const string &test, const string &aim, int enter)
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
fp_command selCommand(vector<string> &input, const User &user)
{
	string		str[] = {"PASS", "USER", "NICK", "JOIN", "QUIT", "KICK", "PING", "PONG", "LIST", "PRIVMSG"};
	fp_command	result[] = {cmd::pass, cmd::user, cmd::nick, cmd::join, cmd::quit, cmd::kick, cmd::ping, cmd::pong, cmd::list, cmd::privmsg,  NULL};
	int			i;

	for (i = -1; i < 10; ++i)
		if (isEqual(input[0], str[i], input.size() >= 1) || 
				isEqual(input[1], str[i], input.size() >= 2))
			break;
	if ((user.getActive() == FALSE && i != 0) || 
		((user.getActive() == HALF || user.getActive() == U_HALF) && i > 2))
	{
		Response::create().to(user).content(ND_ACTIVE).send();
		return (0);
	}

	return result[i];
}

vector<string> split_input(const string &str){
	
	stringstream	sstream(str);
	string			new_str;
	vector<string>	strings;

	while (getline(sstream, new_str, ' '))
	{
		if (str[0] > 33)
			strings.push_back(new_str);
	}
	return strings;
}

/// @brief handles input
/// @param fd 
/// @param input 
void	Server::handleInput(int fd, const string &input)
{
	fp_command 		func;
	string			str;
	vector<string>	commands;

	commands = split_input(input);
	start.setRawString(input);

	if ((func = selCommand(commands, *users[fd])) != NULL)
		func(commands, *users[fd]);
}


static int get_line(int fd, string &line){
	char chr[2] = {0};
	int readed = 0;
	int total_read = 0;;
	while ((readed = recv(fd,chr,1,0)) > 0){
		total_read += readed;
		string append(chr);
		line += append;
		if (chr[0] == '\n')
			break;
	}
	return total_read;
}

// const string& generateReply(int code, User, string message);

void	Server::setUpSocket()
{
	Socket clientSocket;
	vector<struct pollfd> pollfds;

	clientSocket.init(port);
	pollfds.push_back( (struct pollfd){clientSocket.getSocketFd(), POLLIN, 0} );
	while (poll(&pollfds[0], pollfds.size(), -1))//alınan inputların durumunu söyler
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
					int	 clientFd =  clientSocket.Accept();

					fcntl(clientFd, F_SETFL, O_NONBLOCK);
					pollfds.push_back( (struct pollfd){clientFd, POLLIN | POLLOUT} );
					getOrCreateUser(clientFd);
				}
				else
				{
					string line;
					int readed = get_line(pollfds[i].fd,line);
					if (readed > 0){
						cout << line << endl;
						handleInput(pollfds[i].fd,line);
					}
					else if (readed <= 0){
						close(pollfds[i].fd);
						deleteUser(pollfds[i].fd);
					}
				}
			}
		}
	}
	exit (0);
}
