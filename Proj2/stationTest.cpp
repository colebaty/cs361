#include <map>
#include <utility>
#include <iostream>
#include <cassert>

#include "module.h"
#include "station.h"

using namespace std;


int main()
{
    cout << "creating new station" << endl;
    station station;
    
    cout << "------------------------" << endl;

    cout << "adding base/hallway module to station" << endl;

    bool done = false;
    char ans;
    while (!done)
    {
        station.add(_BASE);

        cout << "continue? ";
        cin >> ans;
        done = (ans != 'y');
    }
    

    return 0;
}