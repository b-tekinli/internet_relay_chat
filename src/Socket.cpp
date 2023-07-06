#include "Global.hpp"

Socket::Socket() : fd_socket(0) {}

Socket::~Socket()
{
    Close();
}

bool Socket::Create()
{
    fd_socket = socket(AF_INET, SOCK_STREAM, 0);

    return (fd_socket != -1);
}

bool Socket::Bind(int port)
{
    sockaddr_in connect_int;    // soketin bağlanacağını adres ve port bilgilerini almak için
    
    connect_int.sin_family = AF_INT;
    connect_int.sin_port = htons(port);
    connect_int.sin_addr.s_addr = INADDR_ANY;

    return (bind(fd_socket, (sockaddr*)&connect_int, sizeof(connect_int) != -1));
}

bool Socket::Listen()
{
    return (listen(fd_socket, MAX_CLIENT) != -1);
}

bool Socket::Accept(Socket &newSocket)
{
    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(fd_socket, (sockaddr *)&client, &clientSize);

    if (clientSocket != -1)
    {
        newSocket.fd_socket = clientSocket;
        return true;
    }

    return false;
}


void Socket::Close()
{
    if (fd_socket != 0)
    {
        close(fd_socket);
        fd_socket = 0;
    }
}
