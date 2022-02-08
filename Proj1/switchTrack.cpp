#include <iostream>
#include <queue>
#include <stack>

#include "container.h"
#include "switchTrack.h"

using namespace std;

switchTrack::switchTrack(int maxOnTrack, int maxOnSiding)
{
    _maxOnTrack = maxOnTrack;
    _maxOnSiding = maxOnSiding;
}

bool switchTrack::full()
{
    return _track.size() < _maxOnTrack;
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