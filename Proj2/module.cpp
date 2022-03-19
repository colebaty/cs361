#include <iostream>
#include <utility>
#include <map>

#include "module.h"

using namespace std;

module::module()
{
    _id = 0;
    _type = _BASE;
    _connections = new module*[HALLWAY_MAX_CONNECTIONS];
    initialize();
}

void module::initialize()
{
    _corners.insert(make_pair(_BL, make_pair(0.0, 0.0)));
    _corners.insert(make_pair(_BR, make_pair(HALLWAY_LEN, 0.0)));
    _corners.insert(make_pair(_TR, make_pair(HALLWAY_LEN, HALLWAY_WID)));
    _corners.insert(make_pair(_TL, make_pair(0.0, HALLWAY_WID)));

    for (int i = 0; i < 4; i++)
    {
        _connections[i] = nullptr;
    }
    
}

module::module(int id, double x, double y)
{
    _id = id;
    _type = _BASE;
    _connections = new module*[HALLWAY_MAX_CONNECTIONS];
    initialize();//set corners
    move(x, y);
}

void module::move(double dx, double dy)
{
    map<char, pair<double, double>>::iterator mit = _corners.begin();
    while (mit != _corners.end())
    {
        mit->second.first += dx;
        mit->second.second += dy;
        mit++;
    }
}

void module::display()
{
    cout << "id: " << _id << endl;
    cout << "type: ";
    printType();
    cout << endl;
    cout << "corners: ";
    map<char, pair<double, double>>::iterator mit = _corners.begin();
    while (mit != _corners.end())
    {
        cout << "(" << mit->second.first << ", " << mit->second.second << ") ";
        mit++;
    }
    cout << endl;
    cout << "connections available? ";
    hasAvailable() ? cout << "y" : cout << "n";
    cout << endl;
}

void module::printType()
{
    switch (_type)
    {
    case _BASE:
        cout << "hallway";
        break;
    
    default:
        break;
    }
}

bool module::hasAvailable()
{
    for (int i = 0; i < 4; i++)
    {
        if (_connections[i] == nullptr)
        {
            return true;
        }
    }
    
    return false;
}