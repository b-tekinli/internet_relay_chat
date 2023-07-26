#include <User.hpp>

void deleteUser(int fd, vector <User*> users)
{
    if (users[fd] != 0)
    {    
        delete users[fd];
        users[fd] = 0;
    }
}