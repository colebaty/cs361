#include <iostream>

#include "shiputils.h"
#include "ship.h"
#include "container.h"

using namespace std;

ship::ship()
{
    _id = 0;
    _capacity = 0;
    _contsPerLevel = 0;
    _numLevels = 0;
    _width = 0;
    _length = 0;
}

ship::ship(int id, int capacity)
{
    _id = id;
    _capacity = capacity;

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
    int contID = _id * CONT_BASE_ID + 1;

    container * contptr;                    
    stack<container> * column;
    vector<stack<container>> * layer;

    for (int row = 0; row < _width; row++)
    {
        layer = new vector<stack<container>>;
        for (int col = 0; col < _length; col++)
        {
            column = new stack<container>;
            for (int i = 0; i < _numLevels; i++)
            {
                contptr = new container(contID++);
                column->push(*contptr);
            }
            layer->push_back(*column);
        }
        _cargo.push_back(*layer);
    }

    #ifdef DEBUG
    std::cout << "loaded " << getNumLoadedConts() << " containers into ship " << _id << endl;
    #endif
}

void ship::display()
{
    std::cout << "ship:\t\t" << _id << endl
         << "capacity:\t" << _capacity << endl
         << "numLoaded:\t" << getNumLoadedConts() << endl;
    #ifdef DEBUG
        std::cout << "cont/lvl:\t" << _contsPerLevel << endl
             << "width:\t\t" << _width << endl
             << "length:\t\t" << _length << endl;
        displayCargoInfo();
    #endif
}

#ifdef DEBUG
void ship::displayCargoInfo()
{
    std::cout << "level count <full levels + remaining containers>:" << endl;
    if (_cargo.empty())
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
#endif

container& ship::getNext()
{
    container * cont;
    cont = new container(_cargo[0][0].top());
    _cargo[0][0].pop();

    if (_cargo[0][0].empty())
    {
        _cargo[0].erase(_cargo[0].begin());
    }

    if (_cargo[0].empty())
    {
        _cargo.erase(_cargo.begin());
    }

    return *cont;
}

bool ship::hasNext()
{
    return !(_cargo.empty() || _cargo[0].empty() || _cargo[0][0].empty()); 
}

int ship::getNumLoadedConts()
{
    int sum = 0;

    vector<vector<stack<container>>>::iterator lit = _cargo.begin();
    vector<stack<container>>::iterator sit;

    while (lit != _cargo.end())
    {
        sit = lit->begin();
        while (sit != lit->end())
        {
            sum += sit->size();
            sit = next(sit);
        }
        lit = next(lit);
    }
    
    return sum;
}