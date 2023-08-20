#include <Error.hpp>

void    error(string msg)
{
    cerr << "Error: " << msg << endl;
    exit (-1);
}

void    checkSocket(int sock, string message)
{
    if (sock == -1)
        error(message + "() didn't work as expected");
}
