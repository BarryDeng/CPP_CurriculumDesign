#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "User.h"
using namespace std;
class Manager : public User
{
public:
    void editInfo();
    void addFli();
    void deleteFli();
    void changeFli();
};
#endif // MANAGER_H_INCLUDED
