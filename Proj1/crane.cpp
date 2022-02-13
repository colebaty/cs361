#include <iostream>

#include "container.h"
#include "crane.h"

using namespace std;

crane::crane()
{
    _id = 0;
    _empty = true;
    _cont = nullptr;
    _lastX = 0;
    _lastY = 0;
}

crane::crane(int id)
{ 
    _id = id; 
    _empty = true;
    _cont = nullptr;
    _lastX = 0;
    _lastY = 0;
}

int crane::getContID()
{
    if (_empty) return 0;
    else return _cont->getID();
}

void crane::load(container& cont)
{ 
    if (_empty)
    {
       _cont = &cont; 
       _empty = false;
    }
    else
    {
        cerr << "error: crane already loaded with container " << _cont->getID() << endl;
    }
}

container crane::unload()
{
    _empty = true;
    container cont = *_cont;
    _cont = nullptr;
    return cont;
}

void crane::display()
{
    cout << "crane no. " << _id << " is";
    if (_empty)
    {
        cout << " not loaded" << endl;
    }
    else
    {
        cout << " loaded with container" << endl;
        _cont->display();
    }
}

void crane::getNext(ship * ship)
{
    *_cont = ship->getCont(_lastX % ship->getWidth(), _lastY % ship->getLength());
    _lastX++;
    _lastY++;
}