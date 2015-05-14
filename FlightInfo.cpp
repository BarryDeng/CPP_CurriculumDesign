#include <string>
#include "FlightInfo.h"

FlightInfo::FlightInfo(string s1, string s2)
{
    No = s1;
    StartDate = s2;
    FirstTicket = 0;
    FirstPrice = 0;
    SecondTicket = 0;
    SecondPrice = 0;
}

FlightInfo::~FlightInfo()
{

}

void FlightInfo::setDateTime(string ds, string ts, string te)
{
    StartDate = ds;
    StartTime = ts;
    EndTime = te;
}
void FlightInfo::setFirstPrice(int i1,int i2)
{
    FirstPrice = i1;
    FirstTicket = i2;
}

void FlightInfo::setSecondPrice(int i1,int i2)
{
    SecondPrice = i1;
    SecondTicket = i2;
}

void FlightInfo::setBaseInfo(string s1,string s2)
{
    StartCity = s1;
    EndCity = s2;
}
