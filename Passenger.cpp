#include <iostream>
#include "User.h"
#include "Passenger.h"
#include "FlightInfo.h"
#include <QAction>

Passenger::Passenger(string name, string password) : User(name,name)
{

}

Passenger::Passenger(const Passenger & right)
{
    Id = right.Id;
    Name = right.Name;
    Password = right.Password;
    CreditCardId = right.CreditCardId;
    CreditCardMoney = right.CreditCardMoney;
    CreditCardPassword = right.CreditCardPassword;
    bookInfo = right.bookInfo;
}

Passenger& Passenger::operator = (const Passenger& right)
{
    Id = right.Id;
    Name = right.Name;
    Password = right.Password;
    CreditCardId = right.CreditCardId;
    CreditCardMoney = right.CreditCardMoney;
    CreditCardPassword = right.CreditCardPassword;
    bookInfo = right.bookInfo;
    return *this;
}

void Passenger::setId(string s)
{
    Id = s;
}

bool Passenger::validateCreditCard(string id, string password)
{
    if (id == CreditCardId && password == CreditCardPassword)
        return true;
    else
        return false;
}

bool Passenger::recharge(int i)
{
    setCreditCardMoney(CreditCardMoney + i);
    return true;
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
    CreditCardMoney = d * 100;
}

void Passenger::editInfo(string password,string creditid,string creditpassword)
{
    Password = password;
    CreditCardId = creditid;
    CreditCardPassword = creditpassword;
}
