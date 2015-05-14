#include <iostream>
#include "User.h"
#include "Passenger.h"
#include "FlightInfo.h"

Passenger::Passenger(string name, string password) : User(name,name)
{

}

void Passenger::setId(string s)
{
    Id = s;
}

void Passenger::setCreditCardId(string s)
{
    CreditCardId = s;
}

void Passenger::setCreditCardPassword(string s)
{
    CreditCardPassword = s;
}

void Passenger::setCreditCardMoney(int d)
{
    CreditCardMoney = d;
}

void Passenger::editInfo()
{

}

void Passenger::bookFli()
{
    //BookInfo temp(no,date,seat);
    //bookInfo.push_back(temp);
}

void Passenger::unbookFli()
{

}

void Passenger::changeFli()
{

}
