#include <iostream>
#include <queue>
#include <stack>

#include "container.h"
#include "switchTrack.h"

using namespace std;

switchTrack::switchTrack()
{
    _max = 0;
    _maxSiding = 0;
}

switchTrack::switchTrack(int id, int max)
{
    _id = id; 
    _max = max;
    _maxSiding = _max - 1;
}

bool switchTrack::full()
{
    return _track.size() >= _max;
}

bool switchTrack::empty()
{
    return _track.empty();
}

bool switchTrack::sidingFull()
{
    return _siding.size() >= _maxSiding;
}

void switchTrack::push(container cont)
{
    if(!full())
    {
        _track.push(cont);
    }
    #ifdef DEBUG
    else
        cerr << "error: switch strack " << _id << " full" << endl;
    #endif
}

void switchTrack::pushToSiding()
{
    container * cont;
    if (!sidingFull())
    {
        cont = &_track.front();
        _track.pop();
        _siding.push(*cont);
    }
    #ifdef DEBUG
    else
        cerr << "error: switch strack " << _id << " full" << endl;
    #endif
}

void switchTrack::display()
{
    cout << "switch track: " << _id << endl
         << "num containers on track: " << (_track.empty() ? 0 : _track.size()) << endl
         << "\tnum containers on siding: " << _siding.size() << endl
         << "\tfull:\t" << full() << endl;
}

int switchTrack::getNextDest()
{
    return _track.front().getDest();
}

int switchTrack::getNextSidingDest()
{
    if (!_siding.empty()) return _siding.top().getDest();

    return 0;
}

int switchTrack::getNextSidingID()
{
    return _siding.top().getID();
}

container switchTrack::getNext()
{
    container * cont;
    cont = new container(_track.front());
    _track.pop();
    return *cont;
}

container switchTrack::getNextFromSiding()
{
    container * cont;
    cont = new container(_siding.top());
    _siding.pop();
    return *cont;
}

int switchTrack::getNextContID()
{
    return _track.front().getID();
}

void switchTrack::refresh()
{
    container * cont;
    while(!full() && !_siding.empty())
    {
        cont = &_siding.top();
        _siding.pop();
        _track.push(*cont);
    }
}