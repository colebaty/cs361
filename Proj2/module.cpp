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
    //corners
    _corners.insert(make_pair(_BL, make_pair(0.0, 0.0)));
    _corners.insert(make_pair(_BR, make_pair(HALLWAY_LEN, 0.0)));
    _corners.insert(make_pair(_TR, make_pair(HALLWAY_LEN, HALLWAY_WID)));
    _corners.insert(make_pair(_TL, make_pair(0.0, HALLWAY_WID)));

    //walls
    map<char, pair<double, double>>::iterator mit;

    pair<double, double> * start;
    pair<double, double> * end;

    mit = _corners.begin();
    int wall = 0;

    while (mit != _corners.end())
    {
        start = &mit->second;

        if(next(mit) == _corners.end())
        {
            end = &_corners.begin()->second;
        }
        else
        {
            end = &next(mit)->second;
        }

        _walls.insert(make_pair(wall++, make_pair(start, end)));

        mit++;
    }

    //connections
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
    
    map<int, pair<pair<double, double>*, pair<double, double>*>>::iterator wit = _walls.begin();
    pair<double, double> * start;
    pair<double, double> * end;
    cout << "walls: " << endl;
    while(wit != _walls.end())
    {
        start = wit->second.first;
        end = wit->second.second;

        cout << "\twall " << wit->first << ": (" 
             << start->first << ", " << start->second
             << ") to ("
             << end->first << ", " << end->second
             << ")" << endl;

        wit++;
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

// void module::connect(int srcWall, module& target, int targetWall)
// {
//     _connections[srcWall] = &target;
//     target._connections[targetWall] = this;
//     map<int, pair<pair<double, double>*, pair<double, double>*>>::iterator srcit;
//     srcit = _walls.find(srcWall);

//     map<int, pair<pair<double, double>*, pair<double, double>*>>::iterator dstit;
//     dstit = target._walls.find(targetWall);

//     pair<int, int> * conn = &make_pair(srcWall, targetWall);


// }