#include <iostream>

#include "shiputils.h"
#include "ship.h"
#include "container.h"

using namespace std;

ship::ship()
{
    _id = 0;
    _capacity = 0;
    _numLoadedConts = 0;
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
    _cargo = new vector<stack<container>>;

    int rawContsPerLevel = _capacity * 0.05;
    //round down to nearest multiple of 5
    _contsPerLevel = rawContsPerLevel - (rawContsPerLevel % 5); 
    _numLevels = _capacity / _contsPerLevel;
    _width = _contsPerLevel * 0.1;
    _length = _contsPerLevel / _width;

    fillCargo();
}

void ship::fillCargo()
{
    container * contptr;
    stack<container> * colptr;

    int contID = _id * 10000 + 1;
    vector<vector<stack<container>>> * rowptr = new vector<vector<stack<container>>>;
    for (int col = 0; col < _length; col++)
    {
        colptr = new stack<container>;
        for (int depth = 0; depth < _numLevels; depth++)
        {
            contptr = new container(contID++);
            colptr->push(*contptr);
            _numLoadedConts++;
        }
        _cargo->push_back(*colptr); 
    }

    #ifdef DEBUG
    std::cout << "loaded " << _numLoadedConts << " containers into ship " << _id << endl;
    #endif
}

void ship::display()
{
    std::cout << "ship:\t\t" << _id << endl
         << "capacity:\t" << _capacity << endl
         << "numLoaded:\t" << _numLoadedConts << endl;
    #ifdef DEBUG
        std::cout << "cont/lvl:\t" << _contsPerLevel << endl
             << "width:\t\t" << _width << endl
             << "length:\t\t" << _length << endl;
        displayCargoInfo();
    #endif
}

void ship::displayCargoInfo()
{
    std::cout << "level count <full levels + remaining containers>:" << endl;
    if (_cargo == nullptr)
    {
        std::cout << "\t0+0" << endl;
    }
    else
    {
        std::cout << "\t" << _numLevels << "+" << _capacity % _contsPerLevel << endl;
        std::cout << "container at (0,0) is" << endl;
        _cargo[0][0].top().display();
    }
}

container& ship::getCont(int row, int col)
{
    container * contptr;
    *contptr = _cargo[row][col].top();
    _cargo[row][col].pop();
    _numLoadedConts--;
    
    return *contptr;
}