#ifndef SOCKET_HPP
#define SOCKET_HPP

#include "Global.hpp"

class Socket
{
private:
    int fd_socket;
    sockaddr_in connect_int; // soketin bağlanacağı adres ve port bilgilerini almak için

public:
    Socket(int port);
    ~Socket();

    bool Create();
    bool Bind(int port);
    bool Listen();
    bool Accept(Socket &newSocket);
    bool Connect(string &ipAdress, int port);
    bool Send(string &message);
    int Receive(string &message);
    void SetNonBlocking(bool isNonBlocking);
    void Close();
};

#endif
