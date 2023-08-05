#include <Commands.hpp>

int cmd::notice(const vector<string> &input, User& from)
{
    cout << "girdi" << endl;
    if (input.size() != 3)
    {
        Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(input[0] + NOT_ENOUGH).send();
        return (-1);
    }
    cout << "burdayim" << endl;
    string	msg = str_merge(input);
    cout << "buraya gidiyorum" << endl;
    sendGroup(from, input[1], msg);
    cout << "hey look at me " << endl;
    return (0);
}
 