#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>

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
    }

    cout << "--------------------------" << endl;
    cout << "moving modules around" << endl;

    for (int i = 0; i < modlist.size(); i++)
    {
        modlist[i].move((double) i * HALLWAY_LEN, (double) i * HALLWAY_WID);
    }

    vector<module>::iterator mit = modlist.begin();
    while (mit != modlist.end())
    {
        mit->display();
        mit++;
    }
    
    

    return 0;
}