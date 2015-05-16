#ifndef USERMANAGER_H_INCLUDED
#define USERMANAGER_H_INCLUDED
#include <vector>
#include "Passenger.h"
using std::vector;

class UserManager
{
    vector<Passenger> userlist; // vector容来用来存放用户清单
public:
    UserManager(); // 构造函数
    UserManager(const UserManager&); // 拷贝构造函数
    ~UserManager(); // 析构函数
    void findUserByName(string,Passenger&); // 通过名字来查找用户
    bool addUser(string,string); // 增加用户
    bool deleteUser(string); // 删除用户
    bool editUser(string,const Passenger&); // 编辑用户信息
    bool validate(string,string); // 验证身份信息
};

#endif // USERMANAGER_H_INCLUDED
