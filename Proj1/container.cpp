#include <iostream>

#include "container.h"
#include "shiputils.h"

using namespace std;
container::container()
{ 
    _id = 0; 
    _dest = 0; 
}

container::container(int id)
{
    _id = id;
   _dest = getRand(CONT_MIN_DEST, CONT_MAX_DEST);
}

container::container(const container& other)
{
    _id = other._id;
    _dest = other._dest;
}

void container::display(ostream& out)
{
    out << "container id:\t" << _id << endl
        << "destination:\t" << _dest << endl;
}