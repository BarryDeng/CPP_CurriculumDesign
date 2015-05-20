#ifndef FLIGHTINFO_H_INCLUDED
#define FLIGHTINFO_H_INCLUDED
#include <string>
using std::string;
class FlightInfo
{
    string No; // 航班号
    string StartCity; // 起飞地点
    string EndCity; // 降落地点
    string StartDate; // 日期
    string StartTime; // 起飞时间
    string EndTime; // 降落时间
    int FirstTicket; // 头等舱剩余票数
    int FirstPrice; // 头等舱价格
    int SecondTicket; // 二等舱剩余票数
    int SecondPrice; // 二等舱价格
public:
    FlightInfo() {} //默认构造函数
    FlightInfo(string, string); //带两个参数的构造函数，参数分别为航班号和日期
    ~FlightInfo(); //析构函数
    FlightInfo(const FlightInfo&); // 拷贝构造函数
    FlightInfo& operator = (const FlightInfo&); //重置赋值运算符
    void setDateTime(string,string,string);//设置航班起飞的日期和时间
    void setFirstPrice(int,int); //设置头等舱的价格和剩余票数
    void setSecondPrice(int,int);//设置二等舱的价格和剩余票数
    void setBaseInfo(string,string);//设置出发地和目的地
    void setNo(string);//设置航班号
    string getNo() { return No; }
    string getStartCity() {return StartCity;}
    string getEndCity() {return EndCity;}
    string getStartDate() {return StartDate;}
    string getStartTime() { return StartTime;}
    string getEndTime() { return EndTime;}
    int getFirstTicket() {return FirstTicket;}
    int getFirstPrice() {return FirstPrice / 100;} // 为方便操作，将数值扩大一百倍来表示角和分，返回时则缩小一百倍
    int getSecondTicket() {return SecondTicket;}
    int getSecondPrice() {return SecondPrice / 100;}
};
#endif // FLIGHTINFO_H_INCLUDED
