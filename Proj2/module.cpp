#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <cmath>

#include "module.h"

using namespace std;

module::module()
{
    _id = 0;
    _type = _BASE;
    _maxConnections = HALLWAY_MAX_CONNECTIONS;
    initialize();
}

module::module(int id, double x, double y)
{
    _id = id;
    _type = _BASE;
    _maxConnections = HALLWAY_MAX_CONNECTIONS;
    initialize();//set corners
    move(x, y);
}

void module::initialize()
{
    //corners
    _corners.insert(make_pair(_BL, make_pair(0.0, 0.0)));
    _corners.insert(make_pair(_BR, make_pair(HALLWAY_LEN, 0.0)));
    _corners.insert(make_pair(_TR, make_pair(HALLWAY_LEN, HALLWAY_WID)));
    _corners.insert(make_pair(_TL, make_pair(0.0, HALLWAY_WID)));

    //walls
    map<corners, pair<double, double>>::iterator mit;

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

        _walls.insert(make_pair(getWall(wall++), make_pair(*start, *end)));

        mit++;
    }
}

dirs module::getWall(int i)
{
    switch (i)
    {
    case 0:
        return _BOW;
        break;
    
    case 1:
        return _PORT;
        break;
    
    case 2:
        return _STERN;
        break;
    
    case 3:
        return _SB;
        break;
    
    default:
        break;
    }

    return _LAST;
}

//TODO change to make use of utility::get(std::pair)
void module::updateWalls()
{
    //walls
    map<corners, pair<double, double>>::iterator cit;
    map<dirs, pair<pair<double, double>, pair<double, double>>>::iterator wit;

    cit = _corners.begin();
    wit = _walls.begin();
    // int wall = 0;

    while (wit != _walls.end())
    {
        wit->second.first = cit->second;
        if (next(cit) == _corners.end())
        {
            wit->second.second = _corners.begin()->second;
        }
        else
        {
            wit->second.second = next(cit)->second;
        }

        cit++;
        wit++;
    }
}

void module::move(double dx, double dy)
{
    map<corners, pair<double, double>>::iterator mit = _corners.begin();
    while (mit != _corners.end())
    {
        mit->second.first += dx;
        mit->second.second += dy;
        mit++;
    }
    updateWalls();
}

void module::display()
{
    cout << "id: " << _id << endl;
    cout << "type: ";
    printType();
    cout << endl;

    cout << "corners: ";
    map<corners, pair<double, double>>::iterator mit = _corners.begin();
    while (mit != _corners.end())
    {
        cout << "(" << mit->second.first << ", " << mit->second.second << ") ";
        mit++;
    }
    cout << endl;
    
    map<dirs, pair<pair<double, double>, pair<double, double>>>::iterator wit = _walls.begin();
    pair<double, double> * start;
    pair<double, double> * end;
    cout << "walls: " << endl;
    while(wit != _walls.end())
    {
        start = &wit->second.first;
        end = &wit->second.second;

        cout << "\twall " << dir2char(wit->first)
             << ": (" << start->first << ", " << start->second
             << ") to (" << end->first << ", " << end->second << ")" 
             << endl;
        wit++;
    }

    cout << endl;

    cout << "connections available? ";
    hasAvailable() ? cout << "y" : cout << "n";
    cout << endl;
    if (hasAvailable())
    {
        vector<dirs> * avail = new vector<dirs>(getAvailable());
        if (avail->size() == _maxConnections)
        {
            cout << "\tall walls available for connection" << endl;
        }
        else
        {
            cout << "\tavailable walls : ";
            vector<dirs>::iterator connit = avail->begin();
            while (connit != avail->end())
            {
                cout << dir2char(*connit) << " ";
                connit++;
            }
            cout << endl;
        }
    }

    if (!_connections.empty())
    {
        cout << "connections:" << endl;
        map<dirs, module>::iterator connit = _connections.begin();
        while (connit != _connections.end())
        {
            cout << "\twall " << dir2char(connit->first) << " to module " << connit->second.getID() << endl;
            connit++;
        }
    }
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
    return _connections.size() < _maxConnections;
}

vector<dirs> module::getAvailable()
{
    vector<dirs> * avail = new vector<dirs>;

    if (_connections.find(_BOW) == _connections.end()) avail->push_back(_BOW);
    if (_connections.find(_PORT) == _connections.end()) avail->push_back(_PORT);
    if (_connections.find(_STERN) == _connections.end()) avail->push_back(_STERN);
    if (_connections.find(_SB) == _connections.end()) avail->push_back(_SB);

    return *avail;
}

//TODO flesh out - need to work on connections first
void module::writeConfFile(ofstream& out)
{
    out << _type << endl << endl
        << _id << endl << endl;

    map<corners, pair<double, double>>::iterator cit = _corners.begin();

    while (cit != _corners.end())
    {
        out << cit->second.first << ", " << cit->second.second;
        if (next(cit) != _corners.end()) out << ", ";
        cit++;
    }

    out << endl;

}

void module::writeDataFile(ofstream& out)
{
    map<corners, pair<double, double>>::iterator cit = _corners.begin();

    while (cit != _corners.end())
    {
        out << cit->second.first << " " << cit->second.second << endl;
        cit++;
    }
    out << _corners.begin()->second.first << " " 
        << _corners.begin()->second.second << endl;
 
}

void module::connect(dirs srcWall, module& dst, dirs dstWall)
{
    //check for available connections
    if (dst.hasAvailable())
    {
        //check that target wall is not already connected
        if (dst._connections.find(dstWall) == dst._connections.end())
        {
            cout << "connecting src wall " << dir2char(srcWall) << " of module " << _id
                 << " to dst wall " << dir2char(dstWall) << " of module " << dst._id << endl;
            //connect this to other
            _connections.insert(make_pair(srcWall, dst));
            
            //connect other to this
            dst._connections.insert(make_pair(dstWall, *this));
            align(srcWall, dst, dstWall);
        }
        else
        {
            cerr << "error: dst wall " << dir2char(dstWall) << " of module " << dst._id << " already connected " << endl;
        }
    }
    else
    {
        cerr << "error: dst has no available connections" << endl;
    }
    
}

void module::align(dirs& srcWall, module& dst, dirs& dstWall)
{

}

char module::dir2char(dirs dir)
{
    switch (dir)
    {
    case _BOW:
        return 'N';
        break;
    
    case _STERN:
        return 'S';
        break;
    
    case _SB:
        return 'E';
        break;
    
    case _PORT:
        return 'W';
        break;
    
    default:
        break;
    }

    return _LAST;
}

void module::rotate(double deg)
{
    //convert deg to radian
    double rad = deg / 180 * PI;

    map<corners, pair<double, double>>::iterator cit = _corners.begin();
    double *x, *y;
    double newX, newY;
    while (cit != _corners.end())
    {
        x = &get<0>(cit->second);
        y = &get<1>(cit->second);

        newX = (*x * cos(rad)) - (*y * sin(rad));
        newY = (*x * sin(rad)) + (*y * cos(rad));

        *x = newX;
        *y = newY;

        //correcting for rounding error that makes for very small non-zero answer
        if (abs(*x) < 0.0001) *x = 0;
        if (abs(*y) < 0.0001) *y = 0;

        cit++;
    }

    updateWalls();
}