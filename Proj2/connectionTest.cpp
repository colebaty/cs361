#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>
#include <string>

#include "module.h"
#include "utilities.h"

using namespace std;

int main()
{
    cout << "creating 4 modules" << endl;
    module * mptr;
    vector<module> modlist;

    for (int i = 0; i < 4; i++)
    {
        mptr = new module(i+1);
        modlist.push_back(*mptr);
    }

    for (int i = 0; i < modlist.size(); i++)
    {
        modlist[i].display();
        cout << endl;
    }

    cout << "--------------------------" << endl;
    
    
    //housekeeping
    delete mptr;

    return 0;
}