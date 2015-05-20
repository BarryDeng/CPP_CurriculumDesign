#include <iostream>
#include "User.h"
#include "Passenger.h"
#include "FlightInfo.h"
#include <QAction>
#include <QCryptographicHash>

Passenger::Passenger(string name, string password) : User(name,password)
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
    QString pwdmd5;
    QByteArray bb;
    bb = QCryptographicHash::hash ( QString::fromStdString(password).toLatin1(), QCryptographicHash::Md5 );
    pwdmd5 = bb.toHex();
    if (id == CreditCardId && CreditCardPassword == pwdmd5.toStdString())
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
    QString pwdmd5;
    QByteArray bb;
    bb = QCryptographicHash::hash ( QString::fromStdString(s).toLatin1(), QCryptographicHash::Md5 );
    pwdmd5 = bb.toHex();
    CreditCardPassword = pwdmd5.toStdString();
}

void Passenger::setCreditCardMoney(int d)
{
    CreditCardMoney = d * 100;
}

void Passenger::editInfo(string password,string creditid,string creditpassword)
{
    QString pwdmd5,pwdmd5_2;
    QByteArray bb;
    bb = QCryptographicHash::hash ( QString::fromStdString(password).toLatin1(), QCryptographicHash::Md5 );
    pwdmd5 = bb.toHex();
    bb = QCryptographicHash::hash ( QString::fromStdString(creditpassword).toLatin1(), QCryptographicHash::Md5 );
    pwdmd5_2 = bb.toHex();
    Password = pwdmd5.toStdString();
    CreditCardId = creditid;
    CreditCardPassword = pwdmd5_2.toStdString();
}
