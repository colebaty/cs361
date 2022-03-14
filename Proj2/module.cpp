#include <cmath>

#include "module.h"

using namespace std;

module::module()
{
    _id = 0;
    _type = _BASE;
    
    initialize();
}

void module::initialize()
{
    for (int i = 0; i < 4; i++)
    {
        _corners[i][0] = 0.0;
        _corners[i][1] = 0.0;
    }
    
}

module::module(int id, double x, double y, double diag = DEFAULT_DIAG_DIST)
{
    _corners[0][0] = x;
    _corners[0][1] = y;
    fillCorners(diag);
}

// TODO - fill corners; use side length instead of coords?
void module::fillCorners(double diag)
{
    //fill top-right using diag
    _corners[2][0] += diag;
    _corners[2][1] += diag;

    
}