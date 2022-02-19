#include <iostream>
#include <queue>

#include "shiputils.h"

#include "shipTrack.h"
#include "container.h"

using namespace std;

shipTrack::shipTrack()
{
    _id = 0;
    _ttl = 0;
    _cap = 0;
    _dest = 0;
}

shipTrack::shipTrack(int id, int ttl, int cap)
{
    _id = id;
    _ttl = ttl;
    _cap = cap;
    _dest = getRand(1,9);
}

void shipTrack::push(container cont)
{
    if (!full())
    {
        _contents.push(cont);
    }
    
    #ifdef DEBUG
    else
        cerr << "error: track " << _id << " full" << endl;
    #endif
}

bool shipTrack::full()
{
    return _contents.size() >= _cap;
}

bool shipTrack::ready()
{
    return _ttl < 0 || full();
}

void shipTrack::display()
{
    cout << "track no: " << _id << endl
         << "\tttl: " << _ttl << endl
         << "\tloaded: " << _contents.size() << endl
         << "\tcap: " << _cap << endl
         << "\tfull: " << full() << endl
         << "\tready: " << ready() << endl;
}

void shipTrack::update()
{
    _ttl--;
}