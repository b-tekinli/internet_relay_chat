#include "./inc/Global.hpp"

/*

0 ile 1023 arasındaki portlar Well-known ports olarak adlandılır. 
İşletim sistemleri genel olarak uygulamaların bu portları kullanabilmesi için 
yönetici hesabı ile çalıştırılmalarını şart koşar. Bu sayede kullanıcı seviyesi 
proseslerin bu portları kullanması engellenir.

HTTP/S - 80, 443, SSH - 22, FTP - 20, 21 iyi bilinen port örnekleridir. 
İyi bilinen portları, 1024 ile 49151 arasındaki portlar ile Registered 
ports takip eder. Kayıtlı portlar ICANN tarafından kontrol edilmese de 
topluluk faydası için kayıt edilip yayınlanır.

*/

bool control(char **av)
{
    if (atoi(av[1]) >= 1024 && atoi(av[1]) <= 65535) // The maximum end port (based on the range being configured) cannot exceed 65535
        return true;
    return false;
}

int main(int ac, char **av)
{
    // if (ac < 3 || !control(av))
    // {
    //     cout << "You have entered the missing argument or invalid port" << endl;
    //     return (1);
    // }


    int port = atoi(av[1]);
    string ipAdress = "127.0.0.1";
    string message = "hello world";
    
    Socket sc(port);
    

    sc.Create();
    
    
    if (sc.Bind(port) == false)
        cout << "bind" << endl;
    if ( sc.Listen() == false)
        cout << "listen " << endl;    
    
    if ( sc.Accept(sc) == false)
    {
        cout << "accept" << endl;
        return (1);
    }

    //sc.Connect(ipAdress);
    //sc.Send(message);
    //sc.SetNonBlocking(true);
    //sc.Close();
    
    //setsockopt*/




    

    return (0);
}

