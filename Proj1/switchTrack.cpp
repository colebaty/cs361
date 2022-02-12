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

void switchTrack::display()
{
    cout << "num trains on track: " << _track.size() << endl
         << "full:\t" << full() << endl;
}