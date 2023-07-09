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
    if (atoi(av[1]) >= 1024 && atoi(av[1]) <= 65535) //The maximum end port (based on the range being configured) cannot exceed 65535
        return true;
    return false;
}

int main(int ac, char **av)
{
	if (ac != 3 || !control(av))
	{
        cout << "You have entered the missing argument" << endl;
        return (1);
	}

    Socket sc(atoi(av[1]));

    sc.Create(atoi(av[1]));


    if (!sc.Bind())
    {
        cout << "bind" << endl;
        return (0);
    }
    if (!sc.Listen())
    {
        cout << "list" << endl;
        return (1);
    }
    if (!sc.Accept(sc))
    {
        cout << "accept" << endl;
        return (1);
    }
    
    
    cout << "it s over" << endl;

	return (0);
}
