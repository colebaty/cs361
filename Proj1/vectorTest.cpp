/**
 * @file vectorTest.cpp
 * @author your name (you@domain.com)
 * @brief testing using stacks to represent "slices" of cargo ship containers
 * @version 0.1
 * @date 2022-02-02
 * 
 * Testing simulation of stack "slices" of shipping containers.  A cargo ship 
 * parks broadside at a loading dock, and gantry cranes remove containers from
 * that orientation.
 */
#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <vector>

#include "container.h"

using namespace std;

int main(int argc, char** argv)
{
    //seed srand
    srand(time(NULL));

    cout << "creating a row of ten containers...";

    container * cont;
    vector<container> row;
    for (int i = 0; i < 10; i++)
    {
        cont = new container(i);
        row.push_back(*cont);
    }

    assert(row.size() == 10);
    cout << "pass" << endl;
    
    return 0;
}