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
		{
			cout << "girdide yani" << endl;
			break;
		}
		if (str[i] != ' ' && (str[i + 1] == '\0' || str[i + 1] == ' '))
			len++;
	}

	cout << "----------------------------------" << endl;
	cout << "str size: " << str.size();
	cout << "i : " << i << endl;
	cout << "----------------------------------" << endl; 
	for (; i < str.size(); i++)
		merge += str[i];
	return (merge);
}
