#include <../inc/Socket.hpp>

int MAX_CLIENT = 50;

/*
burada fd değerinin başlangıç değerini 0 ile başlatmamızın sebebi,
soketin oluşmadığını ya da bir hata olduğunu belirleyebilmek.
çünkü bir soket oluştuğunda zaten fd_socket değişkeni
atanan soketin file descriptorını içerecek.
*/
Socket::Socket() : fd_socket(0) {}

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
bool Socket::Create(int port)
{
	int opt = 1;//sorulacak???

	fd_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (fd_socket == -1)
	{
		perror("Socket function doesn't work");
		exit (EXIT_FAILURE);
	}
	//reuse içeriden veya dışarıdan alınanların yeniden kullanılabileceğini söylüyo
	//bazı eski pc lerde socket oluşumunda port eklemelerinde sorun olabiliyo
	//portları birbirine bağlarken sorun çıkmaması adına boru örneği bu kontrol yapılıyor
	if (setsockopt(fd_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	connect_int.sin_family = AF_INET;
	connect_int.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	connect_int.sin_port = htons(port);
	return (fd_socket != -1);
}

/*
bir soketi, argümandan gelecek olan portla bağlamak için kullanacağımız fonksiyon.
*/
bool Socket::Bind()
{
	return (bind(fd_socket, (struct sockaddr *)&connect_int, sizeof(connect_int)) != -1);
}

bool Socket::Listen()
{
	return (listen(fd_socket, MAX_CLIENT) != -1);
}

int Socket::Accept()
{
	socklen_t clientSize = sizeof(connect_int); //loop a alıp veri bekliyor.

	return (accept(fd_socket, (struct sockaddr *)&connect_int, (socklen_t *)&clientSize));
}

/*
soketten veri almak için kullanılır. gelen verileri message parametresine atar
ve alınan bayt sayısını döndürür.


aldığımız verinin tamamlanıp tamamlanmadığını ve daha fazla veri almamız gerektiğini
belirlemek için kullanabiliriz.

mesela byte sayısı 0'sa bağlantının kapandığını ya da hiç veri almadığımızı gösterebiliriz.
*/

bool Socket::init(int port)
{
	Create(port);
	if (getSocketFd() < 0)
	{
		cout << "Cannot open the socket file " << endl;
		return false;
	}
	Bind();
	Listen();
	return true;
}

void Socket::Close()
{
	if (fd_socket != 0)
	{
		close(fd_socket);
		fd_socket = 0;
	}
}

int Socket::getSocketFd()
{
	return this->fd_socket;
}
