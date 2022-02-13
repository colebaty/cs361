#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <stack>

#include "container.h"
#include "ship.h"
#include "crane.h"
#include "switchTrack.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));
 
    ship * shipptr = new ship(1);
    crane * craneptr = new crane(1);
    switchTrack * switchptr = new switchTrack();

    container * contptr;

    cout << "removing container from ship" << endl;
    contptr = &shipptr->getCont(2, 2);
    cout << "----------------------------" << endl;
    contptr->display();
    cout << "----------------------------" << endl;

    cout << "passing container to crane" << endl;
    craneptr->load(*contptr);

    cout << "----------------------------" << endl;
    craneptr->display();
    cout << "----------------------------" << endl;
    
    cout << "unloading container from crane" << endl;
    *contptr = craneptr->unload();
    cout << "----------------------------" << endl;
    craneptr->display();
    cout << "----------------------------" << endl;

    cout << "pushing container to switching track" << endl;
    switchptr->push(*contptr);
    cout << "----------------------------" << endl;
    switchptr->display();
    cout << "----------------------------" << endl;

    cout << "filling switching track from ship" << endl;
    cout << "----------------------------" << endl;
    cout << "before" << endl;
    cout << "----------------------------" << endl;
    shipptr->display();
    cout << "----------------------------" << endl;

    int row = 0;
    int col = 0;
    int width = shipptr->getWidth();
    int length = shipptr->getLength();
    while (!switchptr->full())
    {
        craneptr->getNext(shipptr);
        switchptr->push(craneptr->unload());
    }
    
    cout << "----------------------------" << endl;
    cout << "after" << endl;
    cout << "----------------------------" << endl;
    shipptr->display();
    cout << "----------------------------" << endl;
    cout << "----------------------------" << endl;
    switchptr->display();
    cout << "----------------------------" << endl;
    craneptr->display();
    cout << "----------------------------" << endl;

    //housekeeping
    // delete contptr;
    delete craneptr;
    delete shipptr;
    delete switchptr;
    
    return 0;
}