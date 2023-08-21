#include <Utils.hpp>

void printServer(string msg)
{
	cout << " ----------------------------------------" << endl;
	cout << GREEN << " [Server " << start.getHostname() << "]"  << DEFAULT << endl;
	cout << " Created: " << getTime() << endl;
	cout << " Version: " << VERSION << endl;
	cout << "\n " << MAGENTA + msg  + DEFAULT << endl;
	cout << " ----------------------------------------\n" << endl;
}
