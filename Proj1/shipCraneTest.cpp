#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <stack>

#include "container.h"
#include "crane.h"
#include "ship.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    cout << "--------------------" << endl;
    ship * shipptr = new ship(1);
    shipptr->display();
    cout << "--------------------" << endl;

    container * contptr = &shipptr->getCont(0,0);
    contptr->display();
    cout << "--------------------" << endl;

    crane * craneptr = new crane(100);

    craneptr->load(*contptr);
    craneptr->display();
    cout << "--------------------" << endl;

    contptr = nullptr;

    cout << "crane no " << craneptr->getID() << " unloads container " 
         << craneptr->getContID() << endl;
    contptr = &craneptr->unload();
    contptr->display();
    cout << "--------------------" << endl;
    craneptr->display();
    cout << "--------------------" << endl;
    
    craneptr->load(shipptr->getNext());
    craneptr->display();
    cout << "--------------------" << endl;

    return 0;
}
