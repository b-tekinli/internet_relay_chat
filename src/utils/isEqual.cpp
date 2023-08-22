#include <Utils.hpp>

bool	isEqual(const string &test, const string &aim, int enter)
{
	std::cout << "is eq: " << test << " " << aim << std::endl;
	if (enter == 0)
		return (false);
	int size = aim.size();
	int i;

	for (i = 0; i < size && aim[i] == test[i]; ++i);

	if (size == i)
		return (true);
	return (false);
}
