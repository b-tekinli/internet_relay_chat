#include <Commands.hpp>

string	just_text()
{
	int		i = 0;
	int		key = 0;
	string	str = start.getRawString();
	string	merge = "";

	for (int len = 0; str[i] != '\0'; i++)
	{
		if (len == 2)
			break;
		if (str[i] != ' ' && (str[1] == '\0' || str[1] == ' '))
			len++;
	}

	for (; i < str.size(); i++)
		merge += str[i];
	return (merge);
}
