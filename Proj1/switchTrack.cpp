#include <iostream>
#include <queue>
#include <stack>

#include "container.h"
#include "switchTrack.h"

using namespace std;

switchTrack::switchTrack()
{
    _max = 40;
    _maxSiding = _max - 1;
}

bool switchTrack::full()
{
    return !(_track.size() < _max);
}

bool switchTrack::empty()
{
    return _track.empty();
}

bool switchTrack::sidingFull()
{
    return !(_siding.size() < _maxSiding);
}

void switchTrack::push(container cont)
{
    if(!full())
    {
        _track.push(cont);
    }
}

void switchTrack::pushToSiding(container cont)
{
    _siding.push(cont);
}

void switchTrack::display()
{
    cout << "num trains on track: " << _track.size() << endl
         << "\tnum trains on siding: " << _siding.size() << endl
         << "\tfull:\t" << full() << endl;
}

int switchTrack::getNextDest()
{
    return _track.front().getDest();
}

container& switchTrack::getNext()
{
    container * cont;
    cont = &_track.front();
    _track.pop();
    return *cont;
}