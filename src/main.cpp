#include "../inc/Server.hpp"

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
    Server start(atoi(av[1]), av[2]);

    return (0);
}


// main düzelt (little part) + 
// fcntl yi entegre edeceğiz (we can learn) +?
// her revc gibi kullanılan fonksiyonda poll kullanılacak () +


// fonkisyon pointerları ayaralayacağız
// map üzerinden ayar yapacağız
// murathanın fonksiyonlarına bakacağız
// 



// password almaya çalışalım
// kullanıcı oluşturalım
// kanallara kullanıcı eklemeye çalışalım (map kullanarak)
// bazı basit commandları yazmaya çalışalım

//"a " olma durumu                          (OK)
//join ve multiclass                        ()
//kvirc ye yazı gönder                      ()