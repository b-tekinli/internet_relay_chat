#include "Socket.hpp"


/*
    Negatif bir değere sahip bir port numarası kullanmak, ağ iletişimi standartlarına uygun olmadığı için hatalara neden olur ve beklenmedik sonuçlara yol açar. Bu nedenle, port numaraları her zaman pozitif tam sayı değerleri olarak kabul edilir.

*/

bool control(char **av)
{ && 
    if (atoi(av[1]) >= 0 && atoi(av[1]) <= 65535)//The maximum end port (based on the range being configured) cannot exceed 65535
        return true;
    return false;
}

int main(int ac, char **av)
{
	if (ac < 3 && !control(av));
	{
        cout << "You have entered the missing argument" << endl;
        return (1);
	}
	

	return (0);
}
