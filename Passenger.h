#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include "User.h"
#include "FlightInfo.h"
#include <vector>
using namespace std;
class Passenger : public User
{
    string Id;
    string CreditCardId;
    string CreditCardPassword;
    int CreditCardMoney;
public:
    vector<FlightInfo> bookInfo;
    Passenger() {}
    Passenger(string,string);
    void setId(string);
    void setCreditCardId(string);
    void setCreditCardPassword(string);
    void setCreditCardMoney(int);
    string getCreditCardId() { return CreditCardId; }
    string getCreditCardPassword() { return CreditCardPassword;}
    int getCreditCardMoney() { return CreditCardMoney; }
    string getId() { return Id; }
    void editInfo();
    void bookFli();
    void unbookFli();
    void changeFli();
};


#endif // PASSENGER_H_INCLUDED
