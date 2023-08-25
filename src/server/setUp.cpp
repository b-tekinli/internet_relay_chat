#include <Server.hpp>
#include <Commands.hpp>

static std::string trimString(const std::string& str) {
    std::string trimmed = str;
    
    std::string::size_type pos = trimmed.find_first_not_of(" \t\r\n");
    if (pos != std::string::npos) {
        trimmed.erase(0, pos);
    }
    
    return trimmed;
}

static bool endsWith(const std::string &str1, const std::string &str2){
	string end(str1.end() - str2.size(), str1.end());
	return (str1.size() >= str2.size() && end == str2);
}

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
		if (isEqual(str[i], input[0], str[i].size() >= 1) || 
				isEqual(str[i], input[1], str[i].size() >= 2))
			break;
	if ((user.getActive() == FALSE || user.getActive() == HALF || user.getActive() == U_HALF) && i > 2){
		Response::createReply(ERR_NOTREGISTERED).to(user).content(ND_ACTIVE).send();
		return (0);
	}
	return result[i];
}

vector<string>	split_input(const string &str){
	std::size_t		last_index =  str.find(" :");
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
	if (last_index != string::npos && last_index < str.size() - 1){
		stringstream trail(str.substr(last_index + 2));
		getline(trail,new_str);
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
	Person			*person = getOrCreateUser(fd);
	commands = split_input(trimString(input));
	if ((func = selCommand(commands, *person)) != NULL)
	{
		printClient(input, *person);
		func(commands, *person);
	}
}

static int get_line(int fd, string &line){
	char chr[2] = {0};
	int readed = 0;
	int total_read = 0;;
	while ((readed = recv(fd,chr, 1, 0)) > 0){
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
	Socket					clientSocket;
	vector<struct pollfd>	pollfds;
	string	lines[MAX_CLIENT];

	clientSocket.init(port);
	pollfds.push_back( (struct pollfd){clientSocket.getSocketFd(), POLLIN, 0} );
	while (poll(&pollfds[0], pollfds.size(), -1))
	{
		for (int i = 0; i < int(pollfds.size()); i++)
		{
			if(pollfds[i].revents & POLLIN)
			{
				if (pollfds[i].fd == clientSocket.getSocketFd())
				{
					int	 clientFd =  clientSocket.Accept();

					fcntl(clientFd, F_SETFL, O_NONBLOCK);
					pollfds.push_back( (struct pollfd){clientFd, POLLIN | POLLOUT, 0} );
				}
				else
				{
					string	line;
					int readed = get_line(pollfds[i].fd, line);
					if (readed > 0){
						lines[pollfds[i].fd] += line;
						if (endsWith(lines[pollfds[i].fd],"\n")){
							handleInput(pollfds[i].fd, lines[pollfds[i].fd]);
							lines[pollfds[i].fd] = "";
						}
					}
					else if (readed <= 0 && users[pollfds[i].fd] != NULL){
						vector<string> str;
						pollfds.erase(pollfds.begin() + i);
						deleteUser(pollfds[i].fd);
					}
					else
						close(pollfds[i].fd);
				}
			}
		}
	}
	exit (0);
}
