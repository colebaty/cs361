#include <iostream>

#include "node.h"

using namespace std;

int main()
{
    node n;
    n.display();

    cout << "----------------------" << endl;

    node * nptr = new node(1);

    for (int i = _A; i <= _Z; i++)
    {
        nptr->push(i);
    }

    nptr->display();
    

    return 0;
}
