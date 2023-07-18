#include "inc/Global.hpp"

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

void    setUpSocket(int port)
{
    Socket clientSocket;
    vector<struct pollfd> pollfds;
    struct pollfd socket_fd;
    
    clientSocket.init(port);

    socket_fd.fd = clientSocket.getSocketFd();
    socket_fd.events = POLLIN;

    pollfds.push_back(socket_fd);
    
    if (poll(&pollfds[0], pollfds.size(), -1)){
        for (int i = 0; i < pollfds.size(); i++){
            if(pollfds[i].revents & POLLIN){
                if (pollfds[i].fd == socket_fd.fd){
                    int fd = accept();
                    struct pollfd new_fd;
                    new_fd.fd = fd;
                    new_fd.event = POLLIN | POLLOUT;
                    pollfds.push_back(new_fd);
                }
                else {

                }
            }
        }
    }
    while (1) // fix while
    {
        clientSocket.Accept(clientSocket);
        cout << "s out" << endl;
        break;
    }
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




/*
if (!clientSocket.Create(serverPort))
    {
        cout << "Soket oluşturma hatası!" << endl;
        return 1;
    }

    if (!clientSocket.Connect(serverIP))
    {
        cout << "Sunucuya bağlanma hatası!" << endl;
        return 1;
    }
    else
    {
        cout << "Sunucuya bağlandı!" << endl;
    }


    clientSocket.SetNonBlocking(true);

    int flags = 0;
    
    flags = fcntl(clientSocket.getSocketFd(), F_GETFL, 100); // 0000 0000 0000 1000

    if(flags && O_NONBLOCK) //flags = 0000 0000 0000 0000 && O_NONBLOCK == 0000 0000 0001 0000
        cout << "Bloklayıcı olmayan mod başarılı!" << endl;
    else
        cout << "Bloklayıcı olmayan mod başarısız!" << endl;

    string go;

    while (go[0] != '.')
    {
        getline(cin, go);
        clientSocket.Send(go);
    */


// main düzelt
// fcntl yi entegre edeceğiz
// her revc gibi kullanılan fonksiyonda poll kullanılacak