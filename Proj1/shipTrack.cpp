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

shipTrack::shipTrack(int id, int ttl, int cap, int dest)
{
    _id = id;
    _ttl = ttl;
    _cap = cap;
    _dest = dest;
}

void shipTrack::push(container cont)
{
    if (!full())
    {
        _contents.push(cont);
    }
    
    #ifdef DEBUG
    else
        cerr << "error: shipping track " << _id << " full" << endl;
    #endif
}

bool shipTrack::full()
{
    return _contents.size() >= _cap;
}

bool shipTrack::ready()
{
    return full() || (_ttl < 1 && _contents.size() >= _cap * 0.8);
}

void shipTrack::display()
{
    cout << "ship track: " << _id << endl
         << "\tdest: " << _dest * 100 << endl
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