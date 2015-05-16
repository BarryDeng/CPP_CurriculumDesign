#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
using std::string;
class User
{
protected:
    string Name; // 姓名
    string Password; // 密码
public:
    User() {} // 默认构造函数
    User(string,string); // 姓名和密码的构造函数
    string getName() { return Name;}
    string getPassword() { return Password; }
    void setPassword(string s) { Password = s;}
    void setName(string s) { Name = s;}
    virtual void editInfo(string,string,string) = 0; // 虚函数用来让子类根据情况来修改信息
};

#endif // USER_H_INCLUDED
