#define DEBUG
//uncomment for more debug info

#include <iostream>
#include <map>
#include <utility>

#include "station.h"
#include "module.h"

using namespace std;

station::station()
{
    _id = 0;
    _modID = 100;
    add(_BASE);
}

station::station(int id, types type)
{
    _id = id;
    _modID = 100;
    add(type);
}

void station::getAvailableConnections()
{

}

void station::add(types type)
{
    module * mptr;
    switch (type)
    {
    case _BASE:
        mptr = new module(_modID);
        _manifest.insert(make_pair(_modID, *mptr));
        break;
    
    default:
        break;
    }

    #ifdef DEBUG
    cout << "----------------------" << endl;
    multimap<int, module>::iterator mit = _manifest.find(_modID);
    cout << "added new module with id " << mit->second.getID() << endl;
    mit->second.display();
    cout << "----------------------" << endl;
    #endif

    _modID++;
}