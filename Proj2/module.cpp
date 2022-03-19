#include <utility>
#include <map>

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
    // _corners.insert(_BL, make_pair(0.0, 0.0));
}

module::module(int id, double x, double y)
{
    initialize();//set corners
}