#include <iostream>

#include "container.h"
#include "shiputils.h"

using namespace std;

container::container(int id)
{
    _id = id;

   _dest = getRand(100, 900);
}

void container::display(ostream& out)
{
    cout << "container id:\t" << _id << endl
         << "destination:\t" << _dest << endl;
}