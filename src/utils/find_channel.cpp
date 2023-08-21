#include <Utils.hpp>

bool	find_channel(string target, Person &from)
{
	if (target[0] != '#')
		return (false);
	map < string, vector<Person *> > search = start.getChannels();
	std::map<std::string, vector <Person *> >::iterator it = search.begin();	

	for (; it != search.end(); it++)
	{
		if (isEqual(it->first, target, 1))
		{
			for (int i = 0; i < int(it->second.size()); i++)
			{
				if (isEqual(it->second[i]->getNickName(), from.getNickName(), 1))
				{
					return (true);
				}
			}
			Response::create().to(from).content(NO_MEM + target).send();
		}
	}
	return (false);
}

bool	find_channel(vector <Person *> group, string name)
{
	if (group.size() == 0)
		return (false);
	for (int i = 0; i < int(group.size()); i++)
	{
		if (group[i]->getNickName() == name)
			return (true);
	}
	return (false);
}
