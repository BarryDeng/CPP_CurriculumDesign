#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <vector>
#include "Passenger.h"
using std::vector;

class UserManager
{
    vector<Passenger> userlist;
public:
    UserManager();
    UserManager(const UserManager&);
    ~UserManager();
    bool addUser(string,string);
    bool deleteUser(string);
    bool editUser(string);
    bool validate(string,string);
};

#endif // USERMANAGER_H_INCLUDED
