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

bool shipTrack::full()
{
    return _contents.size() <= _cap;
}

bool shipTrack::ready()
{
    return !(_ttl > 0) || full();
}