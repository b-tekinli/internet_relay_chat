#include "Global.hpp"

/*
burada fd değerinin başlangıç değerini 0 ile başlatmamızın sebebi,
soketin oluşmadığını ya da bir hata olduğunu belirleyebilmek.
çünkü bir soket oluştuğunda zaten fd_socket değişkeni 
atanan soketin file descriptorını içerecek.
*/
Socket::Socket(int port) : fd_socket(0) {
    connect_int.sin_family = AF_INET; 
    connect_int.sin_port = htons(port);
    connect_int.sin_addr.s_addr = INADDR_ANY;
}


/*
soket yok edildiğinde kapatılması gerektiğinden direkt olarak
close fonk. destructorda çağırmak mantıklı bir hareket oldu.
*/
Socket::~Socket()
{
    Close();
}


/*
soketin başarıyla oluşturulup oluşturulmadığını kontrol edecek.
dönecek olan değer oluşturulan soketin kullanılmasına veya 
gerekli hataların uygulanmasına olanak sağlayacak.
*/
bool Socket::Create()
{
    fd_socket = socket(AF_INET, SOCK_STREAM, 0);

    return (fd_socket != -1);
}


/*
bir soketi, argümandan gelecek olan portla bağlamak için kullanacağımız fonksiyon.
*/
bool Socket::Bind()
{
    /*connect_int.sin_family = AF_INET; 
    connect_int.sin_port = htons(port);
    connect_int.sin_addr.s_addr = INADDR_ANY;*/
    return (bind(fd_socket, (sockaddr*)&connect_int, sizeof(connect_int) != -1));
}


bool Socket::Listen()
{
    return (listen(fd_socket, MAX_CLIENT) != -1);
}


bool Socket::Accept(Socket &newSocket)
{
    socklen_t     clientSize = sizeof(connect_int);
    int           clientSocket = accept(fd_socket, (sockaddr *)&connect_int, &clientSize);

    if (clientSocket != -1)
    {
        newSocket.fd_socket = clientSocket;
        return true;
    }
    return false;
}


bool Socket::Connect(string &ipAdress)
{
    inet_pton(AF_INET, ipAdress.c_str(), &(connect_int.sin_addr));
    
    return (connect(fd_socket, (sockaddr*)&connect_int, sizeof(connect_int)) != -1);
}


bool    Socket::Send(string &message)
{
    int sendResult = send(fd_socket, message.c_str(), message.size(), 0);

    return (sendResult != -1);
}

/*
soketten veri almak için kullanılır. gelen verileri message parametresine atar
ve alınan bayt sayısını döndürür.


aldığımız verinin tamamlanıp tamamlanmadığını ve daha fazla veri almamız gerektiğini
belirlemek için kullanabiliriz.

mesela byte sayısı 0'sa bağlantının kapandığını ya da hiç veri almadığımızı gösterebiliriz.
*/
int Socket::Receive(string &message)
{
    char buffer[4096] = { 0 };

    int bytesRead = recv(fd_socket, buffer, sizeof(buffer) - 1, 0);

    if (bytesRead > 0)
        message = buffer;
    return bytesRead;
}


void Socket::Close()
{
    if (fd_socket != 0)
    {
        close(fd_socket);
        fd_socket = 0;
    }
}
