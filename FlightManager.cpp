#include "FlightManager.h"
#include <cstdlib>
#include <fstream>
using namespace std;

FlightManager::FlightManager()
{
    fstream flight;
    flight.open("flightdb.dat",ios::in | ios::binary);
    if (flight.fail())
    {
        exit(2);
    }
    flight.seekg(0L, ios::end);
    if (flight.tellg() == (__int64)0)
       flight.clear();
    else
    {
            size_t total = 0;
            flight.seekg(0L, ios::beg);
            flight.read((char *)&total, sizeof(size_t));
            if (total != 0)
            for (int i = 0; i < total; i++)
            {
                int i_buff[4];
                char c1_buff[50], c2_buff[50], c3_buff[50], c4_buff[50], c5_buff[50], c6_buff[50];
                flight.read((char*)c1_buff,10*sizeof(char));
                flight.read((char*)c2_buff,20*sizeof(char));
                flight.read((char*)c3_buff,20*sizeof(char));
                flight.read((char*)c4_buff,10*sizeof(char));
                FlightInfo t(c1_buff,c4_buff);
                t.setBaseInfo(c2_buff,c3_buff);
                flight.read((char*)c5_buff,10*sizeof(char));
                flight.read((char*)c6_buff, 10*sizeof(char));
                t.setDateTime(c4_buff,c5_buff,c6_buff);
                flight.read((char*)&i_buff[0],sizeof(int));
                flight.read((char*)&i_buff[1],sizeof(int));
                t.setFirstPrice(i_buff[0],i_buff[1]);
                flight.read((char*)&i_buff[2],sizeof(int));
                flight.read((char*)&i_buff[3],sizeof(int));
                t.setSecondPrice(i_buff[2],i_buff[3]);
                flightlist.push_back(t);
            }
        flight.close();
    }
}

FlightManager::FlightManager(const FlightManager &)
{

}

FlightManager::~FlightManager()
{
    fstream flight("flightdb.dat",ios::out | ios::binary);
    size_t total = flightlist.size();
    flight.write((char*)&total,sizeof(size_t));
    vector<FlightInfo>::iterator it;
    if (flightlist.size() != 0)
    for (it = flightlist.begin(); it != flightlist.end(); ++it)
    {
            flight.write((char*)it->getNo().c_str(),10*sizeof(char));
            flight.write((char*)it->getStartCity().c_str(),20*sizeof(char));
            flight.write((char*)it->getEndCity().c_str(),20*sizeof(char));
            flight.write((char*)it->getStartDate().c_str(),10*sizeof(char));
            flight.write((char*)it->getStartTime().c_str(),10*sizeof(char));
            flight.write((char*)it->getEndTime().c_str(), 10*sizeof(char));
            int t = it->getFirstTicket();
            flight.write((char*)&t,sizeof(int));
            t = it->getFirstPrice();
            flight.write((char*)&t,sizeof(int));
            t = it->getSecondTicket();
            flight.write((char*)&t,sizeof(int));
            t = it->getSecondPrice();
            flight.write((char*)&t,sizeof(int));
    }
    flight.close();
}

bool FlightManager::addFlight(const FlightInfo& t)
{
    flightlist.push_back(t);
    return true;
}

bool FlightManager::editFlight(string id)
{
    return true;
}

bool FlightManager::deleteFlight(string id)
{
    return true;
}
