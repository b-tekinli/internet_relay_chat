#include <Commands.hpp>


int cmd::notice(const vector<string> &input, User& from)
{
    if (input.size() < 2 )
    {
        Response::create().to(from).code(ERR_NEEDMOREPARAMS).content(input[0] + NOT_ENOUGH).send();
        return (-1);
    }
    string	msg = str_merge(input);

    sendGroup(from, input[1], ERR_NORECIPIENT, msg);
    return (0);
}
 