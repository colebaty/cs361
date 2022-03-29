#define DEBUG
//uncomment for more debug info

#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "station.h"
#include "module.h"

using namespace std;

station::station()
{
    _id = 0;
    _modID = 100;
}

station::station(int id)
{
    _id = id;
    _modID = 100;
}

void station::showAvailableConnections()
{
    multimap<int, module>::iterator mit = _manifest.begin();
    vector<int> available;
    while (mit != _manifest.end())
    {
        if (mit->second.hasAvailable())
        {
            available.push_back(mit->second.getID());
        }
        mit++;
    }

    cout << "MODULES WITH AVAILABLE CONNECTIONS:" << endl;
    if (!available.empty())
    {
        cout << "\t";
        vector<int>::iterator ait = available.begin();
        while (ait != available.end())
        {
            cout << *ait << " " << endl;
            ait++;
        }
    }
    else
    {
        cout << "NO AVAILABLE CONNECTIONS" << endl;
    }
    
}

void station::add(types type)
{
    module * mptr;
    switch (type)
    {
    case _BASE:
        mptr = new module(_modID);
        break;
    
    default:
        break;
    }

    int target = 0;
    if (!_manifest.empty())
    {
        //add to map
        _manifest.insert(make_pair(mptr->getID(), *mptr));

        //select target module
        showAvailableConnections();
        cout << "TARGET MODULE ID: ";
        cin >> target;
        cout << endl;

        //connect them
        module * dst;
        // *dst = get<module>(*_manifest.find(target));
        vector<dirs> dstWalls = dst->getAvailable();
        if (!dstWalls.empty())
        {
            cout << "MODULE " << dst->getID() << " AVAILABLE CONNECTIONS:" << endl;
            cout << "\t";
            vector<dirs>::iterator wit = dstWalls.begin();
            while (wit != dstWalls.end())
            {
                cout << *wit << " " << endl;
            }
        }
        else
        {
            cout << "MODULE " << dst->getID() << " HAS NO AVAILBLE CONNECTIONS" << endl;
        }
        
    }
    else
    {
        _manifest.insert(make_pair(mptr->getID(), *mptr));
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