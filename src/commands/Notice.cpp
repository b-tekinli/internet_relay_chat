#include <Commands.hpp>

int cmd::notice(const vector<string> &input, User& user)
{
    if (user.getActive() != ACTIVE)
    {
        //write_fd(user.getFd(), NO_PASS);
        return (-1);
    }
    return (0);
}
