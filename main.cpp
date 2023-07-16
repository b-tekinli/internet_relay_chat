#include "./inc/Global.hpp"

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

int main(int ac, char **av)
{
    if (ac != 3 || !control(av))
    {
        cout << "You have entered the missing argument!" << endl;
        return (1);
    }

    string serverIP = av[1];
    int serverPort = atoi(av[2]);
    Socket clientSocket;

    clientSocket.Create(serverPort);
    while (1) // fix while
    {
        if (clientSocket.getSocketFd() < 0)
        {
            cout << "Cannot open the socket file " << endl;
            return 1;
        }
        clientSocket.Bind();
        clientSocket.Listen();
        //clientSocket.Accept(); 

        clientSocket.Receive(ms);
        parser(ms);
        
        break;
    }

    // a = ahmet, mehmet, ceren
    // c = ahmet, kaan
    // d = ceren mehmet
    
    return (0);
}

// create (socket);
//



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
