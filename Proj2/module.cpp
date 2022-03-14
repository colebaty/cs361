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

void module::fillCorners(double diag)
{

}