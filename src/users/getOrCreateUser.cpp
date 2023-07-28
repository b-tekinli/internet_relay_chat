#include <Commands.hpp>

User*   users::getOrCreateUser(int fd, vector <User*> &users)
{
    if (users.size() < fd || users[fd] == 0)
        users.insert(users.begin() + fd, new User(fd));
    return (users[fd]);
}
