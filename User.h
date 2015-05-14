#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
using std::string;
class User
{
    string Name;
    string Password;
public:
    User() {}
    User(string,string);
    string getName() { return Name;}
    string getPassword() { return Password; }
    void setPassword(string s) { Password = s;}
    void setName(string s) { Name = s;}
    virtual void editInfo() = 0;
};

#endif // USER_H_INCLUDED
