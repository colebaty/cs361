#include <iostream>

#include "shiputils.h"
#include "ship.h"
#include "container.h"

using namespace std;

ship::ship()
{
    _id = 0;
    _capacity = 0;
    _cargo = nullptr;
    _contsPerLevel = 0;
    _numLevels = 0;
    _width = 0;
    _length = 0;
}

ship::ship(int id, int capacity)
{
    _id = id;
    _capacity = capacity;
    _cargo = nullptr; //FIX LATER

    int rawContsPerLevel = _capacity * 0.05;
    //round down to nearest multiple of 5
    _contsPerLevel = rawContsPerLevel - (rawContsPerLevel % 5); 
    _numLevels = _capacity / _contsPerLevel;
    _width = _contsPerLevel * 0.1;
    _length = _contsPerLevel - _width;
}

vector<vector<stack<container>>> ship::fillCargo()
{
    _contsPerLevel = _capacity * 0.5;

    //round up to nearest multiple of 5
    _contsPerLevel += _capacity % 5;
    _width = _contsPerLevel * 0.1;
    _length = _contsPerLevel - _width;
}

void ship::display()
{
    cout << "ship:\t\t" << _id << endl
         << "capacity\t" << _capacity << endl
         << "cont/lvl:\t" << _contsPerLevel << endl
         << "width:\t\t" << _width << endl
         << "length:\t\t" << _length << endl;

}