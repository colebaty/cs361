/**
 * @file craneTest.cpp
 * @author your name (you@domain.com)
 * @brief testing operation of a crane
 * @version 0.1
 * @date 2022-02-04
 * 
 * - [ ] test load crane
 * - [ ] test unload crane
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <stack>

#include "container.h"
#include "crane.h"

using namespace std;

int main(int argc, char** argv)
{
    //seed srand
    srand(time(NULL));

    cout << "creating stack of 10 containers...";

    container * contptr;
    stack<container> contents;

    for (int i = 0; i < 10; i++)
    {
        contptr = new container(i);
        contents.push(*contptr);
    }

    assert(contents.size() == 10);
    cout << "done" << endl;


    return 0;
}