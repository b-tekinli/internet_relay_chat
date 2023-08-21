#include <Utils.hpp>

string getColor(int fd)
{
	string colors[] = {YELLOW, MAGENTA, WHITE, BLACK, RED, BLUE, CYAN};
	string color = colors[fd % 7];
	return color;
}
