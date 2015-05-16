#ifndef FLIGHTMANAGER_H_INCLUDED
#define FLIGHTMANAGER_H_INCLUDED
#include <FlightInfo.h>
#include <vector>
using std::vector;

class FlightManager
{
public:
    vector<FlightInfo> flightlist; // 用vector容器来保存flighinfo对象，表示航班信息
    FlightManager(); // 构造函数
    ~FlightManager(); // 析构函数
    FlightManager(const FlightManager&); // 拷贝构造函数
    bool addFlight(const FlightInfo&); // 增加航班
    bool editFlight(string,string,const FlightInfo&); // 编辑航班
    bool deleteFlight(string,string); // 删除航班
    void findFlightByPlace(string,string,string,vector<FlightInfo>&); // 给定起降位置来搜索航班
    void findFlightByNo(string,string,vector<FlightInfo>&); // 给定航班号来搜索航班
};
#endif // FLIGHTMANAGER_H_INCLUDED
