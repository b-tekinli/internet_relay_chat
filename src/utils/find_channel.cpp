#include <Commands.hpp>

bool	find_channel(string target, User &from)
{
	if (target[0] != '#')
		return (false);
	map < string, vector<User*> > search = start.getChannels();
	std::map<std::string, vector <User*> >::iterator it = search.begin();	

	for (; it != search.end(); it++)
	{
		if (isEqual(it->first, target, 1))
		{
			for (int i = 0; i < it->second.size(); i++)
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

bool	find_channel(vector <User*> group, string name)
{
	if (group.size() == 0)
		return (false);
	for (int i = 0; i < group.size(); i++)
	{
		if (group[i]->getNickName() == name)
			return (true);
	}
	return (false);
}
