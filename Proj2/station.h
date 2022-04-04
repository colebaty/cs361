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
        station(int id);

        //public methods
        /**
         * @brief prints a list of modules with available connections
         * 
         */
        void showAvailableConnections();
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

        /**
         * @brief shifts the entire space station by (dx, dy). since the under
         * -lying structure is a multimap, it is a matter of iterating over
         * each member and updating the module element by ca
         * 
         * @param dx 
         * @param dy 
         */
        void move(double dx, double dy);
};


#endif //__STATION_H__