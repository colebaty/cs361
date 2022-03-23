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
    cout << "creating 2 modules" << endl;
    module * mptr;
    vector<module> modlist;

    int modID = 100;
    module * src = new module(modID++);

    src->display();

    modlist.push_back(*new module(modID++));

    for (int i = 0; i < modlist.size(); i++)
    {
        modlist[i].display();
        cout << endl;
    }

    cout << "--------------------------" << endl;
    cout << "connecting N wall of first module to S wall second module" << endl;

    module * dst = &modlist[0];

    src->connect(_N, *dst, _S);

    cout << "--------------------------" << endl;

    src->display();
    cout << endl;
    dst->display();

    cout << "--------------------------" << endl;
    cout << "creating 4 more modules" << endl;

    for (int i = 0; i < 4; i++)
    {
        mptr = new module(modID++);
        modlist.push_back(*mptr);
    }

    for (int i = 2; i < modlist.size(); i++)
    {
        modlist[i].display();
        cout << endl;
    }

    cout << "--------------------------" << endl;

    cout << "connecting remaining modules to module 100" << endl;

    src->connect(_W, modlist[1], _E);
    src->connect(_S, modlist[2], _N);
    src->connect(_E, modlist[3], _W);

    src->display();

    cout << "--------------------------" << endl;
    cout << "displaying module 100" << endl;

    cout << "--------------------------" << endl;
    cout << "attempting to connect to already connected wall" << endl;

    src = &modlist[4];
    dst = &modlist[3];
    src->display();
    cout << endl;
    dst->display();

    cout << endl;
    cout << "104W is already connected" << endl
         << "attempting to connect 105E to 104W" << endl;
    cout << endl;
    
    src->connect(_E, *dst, _W);

    src->display();
    cout << endl;
    dst->display();

    cout << "--------------------------" << endl;
    //housekeeping
    delete mptr;

    return 0;
}