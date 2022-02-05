#include <iostream>

#include "container.h"
#include "crane.h"

using namespace std;

crane::crane()
{
    _id = 0;
    _loaded = false;
}

int crane::getContID()
{
    if (!_loaded) return 0;
    else return _cont->getID();
}

void crane::load(container cont)
{ 
    if (!_loaded)
    {
       *_cont = cont; 
        _loaded = true;
    }
    else
    {
        cerr << "error: crane already loaded with container " << _cont->getID() << endl;
    }
}

container crane::unload()
{
    _loaded = false;
    return *_cont;
}

void crane::display()
{
    cout << "crane no. " << _id << "is ";
    if (!_loaded)
    {
        cout << "not loaded" << endl;
    }
    else
    {
        cout << "loaded with container" << endl;
        _cont->display();
    }
}