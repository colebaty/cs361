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

    ship * shipptr = new ship(100);
    crane * craneptr = new crane(10);
    container * contptr;
    cout << "-----------------------------" << endl;
    int numUnloaded = 0;

    for (int depth = shipptr->getNumLevels() - 1; depth > -1; depth--)
    {
        for (int i = shipptr->getWidth() - 1; i > -1; i--)
        {
            for (int j = shipptr->getLength() - 1; j > -1; j--)
            {
                contptr = &shipptr->getCont(i, j);
                contptr->display();
                cout << "unloaded " << ++numUnloaded << endl;
                cout << "-----------------------------" << endl;
            }
        }
    }

    return 0;
}