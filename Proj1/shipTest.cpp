
/**
 * @file shipTest.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-02-05
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
#include "ship.h"

using namespace std;

int main(int argc, char** argv)
{
    //seed srand
    srand(time(NULL));

    cout << "creating single default ship...";

    ship * shipptr = new ship();
    assert(shipptr->getID() == 0);
    cout << "done" << endl;

    cout << "----------------------------" << endl;
    shipptr->display();
    cout << "----------------------------" << endl;

    cout << "testing access of empty cargo hold...";
    assert(shipptr->getCont(0, 0) == nullptr);
    cout << "done" << endl;
    cout << "----------------------------" << endl;
    delete shipptr;

    cout << "creating single ship with id 1...";
    shipptr = new ship(1);
    assert(shipptr->getID() == 1);
    assert(MIN_CAPACITY <= shipptr->getCapacity()
            && shipptr->getCapacity() <= MAX_CAPACITY);
    cout << "done" << endl;

    cout << "----------------------------" << endl;
    shipptr->display();
    cout << "----------------------------" << endl;

    int prevLoaded = shipptr->getNumLoadedConts();
    cout << "removing container at (1, 1)...";
    container * contptr;
    contptr = shipptr->getCont(1, 1);
    cout << "done" << endl;

    cout << "----------------------------" << endl;
    cout << "removed container:" << endl;
    assert(shipptr->getNumLoadedConts() == prevLoaded - 1);
    contptr->display();
    cout << "----------------------------" << endl;

    cout << "----------------------------" << endl;
    shipptr->display();
    cout << "----------------------------" << endl;
    //housekeeping

    delete shipptr;

    return 0;
}