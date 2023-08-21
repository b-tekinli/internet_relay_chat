#include <Utils.hpp>

string	to_str(int	number)
{
	ostringstream oss;

	oss << number;
	return (oss.str().c_str());
}
