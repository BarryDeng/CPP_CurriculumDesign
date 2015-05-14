#ifndef FLIGHTMANAGER_H_INCLUDED
#define FLIGHTMANAGER_H_INCLUDED
#include <FlightInfo.h>
#include <vector>
using std::vector;

class FlightManager
{
public:
    vector<FlightInfo> flightlist;
    FlightManager();
    ~FlightManager();
    FlightManager(const FlightManager&);
    bool addFlight(const FlightInfo&);
    bool editFlight(string);
    bool deleteFlight(string);
};
#endif // FLIGHTMANAGER_H_INCLUDED
