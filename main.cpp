#include "inc/Global.hpp"
#include <unistd.h>

/*
    Negatif bir değere sahip bir port numarası kullanmak,
    ağ iletişimi standartlarına uygun olmadığı için hatalara
    neden olur ve beklenmedik sonuçlara yol açar.
    Bu nedenle, port numaraları her zaman pozitif tam sayı
    değerleri olarak kabul edilir.
*/

bool control(char **av)
{
    int port = atoi(av[2]);

    if (port >= 1024 && port <= 65535)
        return true;
    return false;
}

typedef int (*fp_command)(const vector<string> &input, const User &user);

fp_command selCommand(const vector<string> &input) //büyük harf olması gerekiyor
{
    string *str = {"JOIN", "NICK", "QUIT", };

    for (int i = 0; i < 2; i++)
    {
        if (input[i] == "JOIN")
        {

        }
        else if (input[i] == "NICK")
        {

        }
        else if (input[i] == "QUIT")
        {

        }
        else if (input[i] == "KILL")
        {

        }
        else if (input[i] == "PING")
        {

        }
        else if (input[i] == "PONG")
        {

        }
        else if (input[i] == "WHO")
        {

        }
        else if (input[i] == "USER")
        {

        }
        else if (input[i] == "PASS")
        {

        }
        else
        {

        }
    }
}


void handleInput(const string &input){
    string s;
    stringstream sstream(input);
    vector<string> commands;

    while (getline(sstream, s, ' ')){
        commands.push_back(s);
    }
    // create command from input
    selCommand(command);
    
}

void    setUpSocket(int port)
{
    Socket clientSocket;
    vector<struct pollfd> pollfds;
    
    clientSocket.init(port);
    pollfds.push_back((struct pollfd){clientSocket.getSocketFd(), POLLIN});
    while (poll(&pollfds[0], pollfds.size(), -1)){

        for (int i = 0; i < pollfds.size(); i++){   

            if(pollfds[i].revents & POLLIN){
                
                if (pollfds[i].fd == clientSocket.getSocketFd()){ // Connected to socket
                    /**
                    * yeni bir bağlantı oluşturulup oluşturulmadığını kontorl edecek ve eğer yeni
                    * bir bağlantı varsa fonsiyonun içerisine girip acceptleyecek
                    * yeni bağlnatı olduğunu nasıl anlıyor? 
                    */
                    int clientFd =  clientSocket.Accept();
    				fcntl(clientFd, F_SETFL, O_NONBLOCK);
                    pollfds.push_back((struct pollfd){clientFd, POLLIN | POLLOUT});
                    cout << "New client connected!" << endl;
                }
                else { // Connected to client
                    char input[512] = {0};
                    int	readed = recv(pollfds[i].fd, input, sizeof(input) - 1,  0);
					if (readed <= 1)
						close(pollfds[i].fd);
                    handleInput(string(input));
                }
            }
        }
    }
	exit (0);
}

int main(int ac, char **av) // 8080 emakas
{
    if (ac != 3 || !control(av))
    {
        cout << "You have entered the missing argument!" << endl;
        cout << "./irc <password> <port>" << endl;
        return (1);
    }
    string serverIP = av[1];
    int serverPort = atoi(av[2]);

    setUpSocket(serverPort);
    return (0);
}


// main düzelt (little part) + 
// fcntl yi entegre edeceğiz (we can learn) +?
// her revc gibi kullanılan fonksiyonda poll kullanılacak () +


// fonkisyon pointerları ayaralayacağız
// map üzerinden ayar yapacağız
// murathanın fonksiyonlarına bakacağız
// 

