#include <Server.hpp>

Server start;

/*
	Negatif bir değere sahip bir port numarası kullanmak,
	ağ iletişimi standartlarına uygun olmadığı için hatalara
	neden olur ve beklenmedik sonuçlara yol açar.
	Bu nedenle, port numaraları her zaman pozitif tam sayı
	değerleri olarak kabul edilir.
*/
bool control(char **av)
{
	int port = atoi(av[1]);

	if (port >= 1024 && port <= 65535)
		return true;
	return false;
}

int main(int ac, char **av) // 8080 emakas
{
	if (ac != 3 || !control(av))
	{
		cout << "You have entered the missing argument!" << endl;
		cout << "./irc <port> <password>" << endl;
		return (1);
	}
	start.setPort(atoi(av[1]));
	start.setPassword(av[2]);
	start.toBegin();


	//User u;
	//u.setNickName("nick");
	//std::string content = "Example reply content";

	//std::string numeric = generateReply(RPL_WELCOME, u, content);
	//std::string normal = generateReply(RPL_TOPIC, u, content);


	return (0);
}


//komutları yazacağız
//private message check işlemlerini halletmem gerekiyor.
//numeric bir şekilde kodu göndereceğiz
//Kvirc'de test edeceğiz
