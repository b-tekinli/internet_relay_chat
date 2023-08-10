#include <Commands.hpp>

bool	isEqual(const string &test, const string &aim, int enter)
{
	if (enter == 0)
		return (false);
	int size = aim.size();
	int i;

	for (i = 0; i < size && aim[i] == test[i]; ++i);

	if (size == i)
		return (true);
	return (false);
}
