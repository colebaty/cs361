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
#include "ship.h"

using namespace std;

int main(int argc, char** argv)
{
    //seed srand
    srand(time(NULL));

    cout << "creating crane with id 1..." << endl;
    crane crane(1);
    cout << "crane " << crane.getID() << " should be empty" << endl;
    cout << "--------------------------" << endl;
    crane.display();
    cout << "--------------------------" << endl;

    cout << "loading crane 1 with a single container" << endl;
    container * contptr;
    contptr = new container();
    crane.load(*contptr);
    cout << "crane " << crane.getID() << " should be empty..." << endl;

    assert(!crane.empty());
    cout << "pass" << endl;

    cout << "expecting container id 0, dest 0" << endl;
    cout << "--------------------------" << endl;
    crane.display();
    cout << "--------------------------" << endl;

    cout << "unloading crane...";
    *contptr = crane.unload();
    assert(crane.empty());
    cout << "pass" << endl;

    delete contptr;

    cout << "creating stack of 10 containers...";

    stack<container> contents;

    for (int i = 0; i < 10; i++)
    {
        contptr = new container(i);
        contents.push(*contptr);
    }

    assert(contents.size() == 10);
    cout << "done" << endl;

    cout << "--------------------------" << endl;
    cout << "removing one container from stack to crane...";

    crane.load(contents.top());
    contents.pop();
    assert(contents.size() == 9);
    cout << "done" << endl;

    cout << "crane should be loaded...";
    assert(!crane.empty());
    cout << "done" << endl;

    cout << "unloading crane...";
    crane.unload();
    assert(crane.empty());
    cout << "done" << endl;

    cout << "removing all containers from stack...";
    while (!contents.empty())
    {
        crane.load(contents.top());
        contents.pop();
        crane.unload();
    }
    assert(crane.empty());
    assert(contents.empty());
    cout << "done" << endl;

    cout << "--------------------------" << endl;
    ship * shipptr = new ship(1);
    cout << "--------------------------" << endl;

    cout << "crane " << crane.getID() << " getting next cont from ship" << endl;
    crane.getNext(shipptr);
    assert(!crane.empty());
    crane.display();

    //housekeeping
    delete contptr;
    delete shipptr;

    return 0;
}