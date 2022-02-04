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
#include <stack>

#include "container.h"

using namespace std;
struct teststruct {
    int id = 0;
    bool isState = false;
};

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
    cout << "displaying contents of container row" << endl;
    for (int i = 0; i < row.size(); i++)
    {
        row[i].display();
        cout << endl;
    }

    cout << "--------------------------" << endl;

    cout << "creating a slice/stack of 10 rows" << endl;
    stack<vector<container>> slice;
    vector<container> * rowptr;

    int id = 0;
    for (int i = 0; i < 10; i++)
    {
        rowptr = new vector<container>;
        for (int j = 0; j < 10; j++)
        {
            cont = new container(id++);
            rowptr->push_back(*cont);
        }
        slice.push(*rowptr);
    }

    while (!slice.empty())
    {
        row = slice.top();
        for (int i = 0; i < row.size(); i++)
        {
            row[i].display();
            cout << endl;
        }

        slice.pop();
        cout << "-------------------------" << endl;
    }
    
    cout << "--------------end of slice" << endl;
    
    // do columns of stacks?
    cout << "---------------------" << endl
         << "creating layers of columns of stacks" << endl;

    stack<container> * colptr;

    vector<stack<container>> layer;

    id = 100;
    for (int i = 0; i < 5; i++)
    {
        colptr = new stack<container>;
        for (int j = 0; j < 5; j++)
        {
           cont = new container(id++);
           colptr->push(*cont); 
        }
        layer.push_back(*colptr);
    }

    for (int i = 0; i < layer.size(); i++)
    {
        while(!layer[i].empty())
        {
            layer[i].top().display();
            cout << endl;
            layer[i].pop();
        }
        cout << "----------------------" << endl;
    }

    return 0;
}