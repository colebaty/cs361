#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <stack>

#include "container.h"
#include "ship.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    ship * shipptr = new ship(1);
    shipptr->display();

    container * contptr = &shipptr->getCont(0,0);
    contptr->display();

    return 0;
}
