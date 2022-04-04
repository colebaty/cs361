// #define DEBUG
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
            cout << *ait << " ";
            ait++;
        }
    }
    else
    {
        cout << "NO AVAILABLE CONNECTIONS" << endl;
    }

    cout << endl;
    
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

        //select target module
        showAvailableConnections();
        cout << "TARGET MODULE ID: ";
        cin >> target;
        cout << endl;

        //connect them
        multimap<int, module>::iterator dst;
        dst = _manifest.find(target);
        vector<dirs> dstWalls = dst->second.getAvailable();
        vector<dirs> srcWalls = mptr->getAvailable();
        dirs targetWall;
        dirs srcWall;
        if (!dstWalls.empty())
        {
            cout << "MODULE " << dst->second.getID() << " AVAILABLE CONNECTIONS:" << endl;
            cout << "\t";
            vector<dirs>::iterator wit = dstWalls.begin();
            while (wit != dstWalls.end())
            {
                cout << *wit << " ";
                wit++;
            }
            cout << endl << "TARGET WALL OF TARGET MODULE: ";
            int in;
            cin >> in;
            targetWall = (dirs) in;


            cout << "SOURCE WALL AVAILABLE CONNECTIONS: "
                 << "\t";
            wit = srcWalls.begin();
            while (wit != srcWalls.end())
            {
                cout << *wit << " ";
                wit++;
            }
            cout << endl << "TARGET WALL SOURCE MODULE: ";
            cin >> in;
            srcWall = (dirs) in;

            mptr->connect(srcWall, dst->second, targetWall);
            _manifest.insert(make_pair(mptr->getID(), *mptr));

        }
        else
        {
            cout << "MODULE " << dst->second.getID() << " HAS NO AVAILBLE CONNECTIONS" << endl;
        }

        cout << endl;
        
    }
    else
    {
        //add first module to map
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

void station::move(double dx, double dy)
{
    multimap<int, module>::iterator mit = _manifest.begin();

    while(mit != _manifest.end())
    {
        mit->second.move(dx, dy);
        mit++;
    }
}

void station::display()
{
    map<int, module>::iterator mit = _manifest.begin();

    while (mit != _manifest.end())
    {
        mit->second.display();
        mit++;
    }

}