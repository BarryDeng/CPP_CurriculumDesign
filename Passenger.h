#ifndef PASSENGER_H_INCLUDED
#define PASSENGER_H_INCLUDED
#include "User.h"
#include "FlightInfo.h"
#include <vector>
using namespace std;
class Passenger : public User
{
    string Id; // 身份证号
    string CreditCardId; // 信用卡账号
    string CreditCardPassword; // 信用卡密码
    int CreditCardMoney; // 信用卡金额
public:
    vector<FlightInfo> bookInfo; // vector容器保存的已经订购的航班信息
    Passenger() {} // 默认构造函数
    Passenger(const Passenger&); // 拷贝构造函数
    Passenger(string,string); // 有账号和密码的构造函数
    Passenger& operator = (const Passenger&); // 重载赋值运算符
    void setId(string);
    void setCreditCardId(string);
    void setCreditCardPassword(string);
    void setCreditCardMoney(int);
    bool validateCreditCard(string,string); // 验证信用卡信息
    bool recharge(int); // 充值账户
    string getCreditCardId() { return CreditCardId; }
    string getCreditCardPassword() { return CreditCardPassword;}
    int getCreditCardMoney() { return CreditCardMoney / 100; }
    string getId() { return Id; }
    void editInfo(string,string,string); // 编辑信息
};


#endif // PASSENGER_H_INCLUDED
