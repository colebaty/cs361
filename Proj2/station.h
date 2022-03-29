#ifndef __STATION_H__
#define __STATION_H__

#include <iostream>
#include <map>

#include "module.h"

using namespace std;

class station {
    private:
        multimap<int, module> _manifest;
        int _id;
        int _modID;
        //private methods
    public:
        station();
        station(int id, types type = _BASE);
        /**
         * @brief prints a list of modules with available connections
         * 
         */
        void getAvailableConnections();
        /**
         * @brief adds unconnected src module to connected dst module, making
         * connection along given source and destination walls
         * 
         * @param srcWall 
         * @param src 
         * @param dstWall 
         * @param dst 
         */
        void add(types type);
        //public methods
};


#endif //__STATION_H__