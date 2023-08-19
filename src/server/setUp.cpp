#include <Server.hpp>
#include <Commands.hpp>

/**
 * selcommand used for select command for given input
 * @param input: Input string
 * @return fp_command is the type of the function that represents 
 */
fp_command	selCommand(vector<string> &input, const Person &user)
{
	string		str[] = {"PASS", "USER", "NICK", "JOIN", "QUIT", "KICK", "PING", "PONG", "PRIVMSG", "NOTICE"};
	fp_command	result[] = {cmd::pass, cmd::user, cmd::nick, cmd::join, cmd::quit, cmd::kick, cmd::ping, cmd::pong, cmd::privmsg, cmd::notice, NULL};
	int			i;

	for (i = -1; i < 10; ++i)
		if (isEqual(input[0], str[i], input.size() >= 1) || 
				isEqual(input[1], str[i], input.size() >= 2))
			break;
	if ((user.getActive() == FALSE || user.getActive() == HALF || user.getActive() == U_HALF) && i > 2)
		return (0);
	return result[i];
}

vector<string>	split_input(const string &str){
	std::size_t		last_index =  str.find_last_of(':');
	stringstream	sstream(str.substr(0,last_index != string::npos ? last_index : str.length()));
	string			new_str;
	vector<string>	strings;
	int				i = 0;

	while (getline(sstream, new_str, ' '))
	{
		while (new_str.size() > 0 && new_str[new_str.size() - 1] < 33)
			new_str = new_str.substr(0, new_str.size() - 1);
		if (new_str[0] > 33)
			strings.push_back(new_str);
		i++;
	}
	if (last_index != string::npos){
		strings.push_back(str.substr(last_index));
	}
	return strings;
}

void print_args(vector<string> &args){
	for (int i = 0; i < args.size(); i++){
		cout << "ARG: " << args[i] << endl;
	}
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
	
	cout << "INPUT: " << input << endl;
	cout << "INPUT (size): " << commands.size() << endl;
	if ((func = selCommand(commands, *(users[fd]))) != NULL)
			func(commands, *(users[fd]));
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
		memset(chr, 0, 2);
	}
	return total_read;
}

void	Server::setUpSocket()
{
	Socket clientSocket;
	vector<struct pollfd> pollfds;

	clientSocket.init(port);
	pollfds.push_back( (struct pollfd){clientSocket.getSocketFd(), POLLIN, 0} );
	while (poll(&pollfds[0], pollfds.size(), -1)) //alınan inputların durumunu söyler
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
					if (readed > 0)
						handleInput(pollfds[i].fd,line);
					else if (readed <= 0){
						deleteUser(pollfds[i].fd);
						close(pollfds[i].fd);
					}
				}
			}
		}
	}
	exit (0);
}
