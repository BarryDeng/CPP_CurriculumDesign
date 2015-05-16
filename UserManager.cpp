#include "UserManager.h"
#include <fstream>
#include <QAction>
#include <QString>
#include "FlightInfo.h"
#include <cstdlib>
#include <cstring>

UserManager::UserManager()  // 文件读写放置于构造函数中
{
    fstream user;
    user.open("userdb.dat",ios::in | ios::binary);
    if (!user)
    {
        exit(1);
    }
    user.seekg(0L,ios::end);
    if (user.tellg() == (__int64)0)
        user.clear();
    else
    {
        size_t total = 0;
        user.seekg(0L,ios::beg);
        user.read((char *)&total, sizeof(size_t));
        for (int i = 0; i < total; i++)
        {
            Passenger temp;
            char c_buff[50];
            user.read((char*)c_buff,18*sizeof(char));
            temp.setId(c_buff);
            user.read((char*)c_buff,10*sizeof(char));
            temp.setName(c_buff);
            user.read((char*)c_buff,20*sizeof(char));
            temp.setPassword(c_buff);
            user.read((char*)c_buff,20*sizeof(char));
            temp.setCreditCardId(c_buff);
            user.read((char*)c_buff,20*sizeof(char));
            temp.setCreditCardPassword(c_buff);
            user.read((char*)c_buff,sizeof(int));
            temp.setCreditCardMoney(atoi(c_buff));
            size_t total;
            user.read((char*)&total,sizeof(size_t));
            for (int i = 0; i < total; ++i)
            {
                string id, date;
                user.read((char*)c_buff,6*sizeof(char));
                id = c_buff;
                user.read((char*)c_buff, 8*sizeof(char));
                date = c_buff;
                FlightInfo t(id,date);
                temp.bookInfo.push_back(t);
            }
            userlist.push_back(temp);
        }
    }
    user.close();
}

UserManager::UserManager(const UserManager &) //  避免自动生成的拷贝构造函数
{

}

bool UserManager::addUser(string name, string password) //增加新用户
{
    Passenger temp(name,password);
    userlist.push_back(temp);
    return true;
}

bool UserManager::deleteUser(string name) // 删除用户
{
    vector<Passenger>::iterator it;
    for (it = userlist.begin(); it != userlist.end(); it++)
        if (it->getName() == name)
        {
            it = userlist.erase(it);
            return true;
        }
    return false;
}

bool UserManager::editUser(string name,const Passenger& pgr) // 编辑用户
{
    vector<Passenger>::iterator it;
    for (it = userlist.begin(); it != userlist.end(); ++it)
    {
        if (it->getName() == name)
        {
            *it = pgr;
            return true;
        }
    }
    return false;
}

bool UserManager::validate(string name, string password) // 验证身份信息
{
    vector<Passenger>::iterator it;
    for (it = userlist.begin(); it != userlist.end(); it++)
        if (it->getName() == name && it->getPassword() == password)
            return true;
    return false;
}

UserManager::~UserManager() // 文件读写放置于析构函数中
{
    fstream user;
    user.open("userdb.dat",ios::out | ios::binary);
    vector<Passenger>::iterator it;
    size_t total = userlist.size();
    user.write((char*)&total,sizeof(size_t));
    if (!userlist.empty())
    for (it = userlist.begin(); it != userlist.end(); ++it)
    {
        char t[50];
        strcpy_s(t,it->getId().c_str());
        user.write((char*)t,18*sizeof(char));
        strcpy_s(t,it->getName().c_str());
        user.write((char*)t,10*sizeof(char));
        strcpy_s(t,it->getPassword().c_str());
        user.write((char*)t,20*sizeof(char));
        strcpy_s(t,it->getCreditCardId().c_str());
        user.write((char*)t,20*sizeof(char));
        strcpy_s(t,it->getCreditCardPassword().c_str());
        user.write((char*)t,20*sizeof(char));
        int m = it->getCreditCardMoney();
        user.write((char*)&m,sizeof(int));
        size_t n = it->bookInfo.size();
        user.write((char*)&n,sizeof(size_t));
        if (n != 0)
        for (int i = 0; i < n; ++i)
        {
            user.write((char*)it->bookInfo[i].getNo().c_str(),6 * sizeof(char));
            user.write((char*)it->bookInfo[i].getStartDate().c_str(), 8*sizeof(char));
        }
    }
    user.close();
}

void UserManager::findUserByName(string name,Passenger &temp)
{
    vector<Passenger>::iterator it;
    for (it = userlist.begin(); it != userlist.end(); it++)
        if (it->getName() == name)
            temp = *it;
}
