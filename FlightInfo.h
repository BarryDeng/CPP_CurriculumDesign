#ifndef FLIGHTINFO_H_INCLUDED
#define FLIGHTINFO_H_INCLUDED
#include <string>
using std::string;
class FlightInfo
{
    string No;
    string StartCity;
    string EndCity;
    string StartDate;
    string StartTime;
    string EndTime;
    int FirstTicket;
    int FirstPrice;
    int SecondTicket;
    int SecondPrice;
public:
    FlightInfo() {}
    FlightInfo(string, string);
    ~FlightInfo();
    void setDateTime(string,string,string);
    void setFirstPrice(int,int);
    void setSecondPrice(int,int);
    void setBaseInfo(string,string);
    string getNo() { return No; }
    string getStartCity() {return StartCity;}
    string getEndCity() {return EndCity;}
    string getStartDate() {return StartDate;}
    string getStartTime() { return StartTime;}
    string getEndTime() { return EndTime;}
    int getFirstTicket() {return FirstTicket;}
    int getFirstPrice() {return FirstPrice;}
    int getSecondTicket() {return SecondTicket;}
    int getSecondPrice() {return SecondPrice;}
};
#endif // FLIGHTINFO_H_INCLUDED
