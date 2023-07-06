#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <poll.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <vector>

#include "Global.hpp"

class Socket
{
private:
    int fd_socket;

public:
    Socket();
    ~Socket();

    bool Create();
    bool Bind(int port);
    bool Listen();
    bool Accept(Socket &newSocket);
    bool Connect();
    void SetNonBlocking();
    bool Send();
    int Receive();
    void Close();
};

#endif
