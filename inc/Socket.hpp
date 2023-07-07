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
#include <cstring>

#include "Global.hpp"


class Socket
{
    private:
        int         fd_socket;
        sockaddr_in connect_int; // soketin bağlanacağı adres ve port bilgilerini almak için

    public:
        Socket(int port);
        ~Socket();

        bool    Create();
        bool    Bind();
        bool    Listen();
        bool    Accept(Socket &newSocket);
        bool    Connect(string &ipAdress);
        bool    Send(string &message);
        void    SetNonBlocking();
        int     Receive();
        void    Close();
    };

#endif
