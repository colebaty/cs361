#ifndef __SPACESTATION_H__
#define __SPACESTATION_H__

#include <map>
#include <utility>

#include "module.h"

using namespace std;

class spaceStation {
    private:
        int _id;
        multimap<int, module> _modules;
        //private methods
    public:
        //public methods
};


#endif //__SPACESTATION_H__