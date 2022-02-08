#include <iostream>
#include <queue>
#include <stack>

#include "container.h"
#include "switchTrack.h"

using namespace std;

switchTrack::switchTrack()
{
    _max = 40;
}

bool switchTrack::full()
{
    return !(_track.size() < _max);
}

void switchTrack::push(container cont)
{
    if(!full())
    {
        _track.push(cont);
    }
    else
    {
        cerr << "error: track full" << endl;
    }
}

void switchTrack::pushToSiding(container cont)
{
    if (_siding.size() < _max - 1)
    {
        _siding.push(cont);
    }
}

void switchTrack::display()
{
    cout << "num trains on track: " << _track.size() << endl
         << "num trains on siding: " << _siding.size() << endl
         << "full:\t" << full() << endl;
}