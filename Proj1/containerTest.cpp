#include <iostream>
#include <assert.h>
#include <queue>

#include "container.h"

using namespace std;

int main(int argc, char** argv)
{
    //seed srand
    srand(time(NULL));

    cout << "creating new container with id = 1" << endl;
    container cont = container(1);
    
    cout << "testing container id == 1...";
    assert(cont.getID() == 1);
    cout << "pass" << endl;

    cont.display();
    cout << endl;

    cout << "creating new container pointer with id = 2" << endl;

    container * contptr = new container(2);

    cout << "testing container id == 2...";
    assert(contptr->getID() == 2);
    cout << "pass" << endl;

    contptr->display();
    cout << endl;

    delete contptr;

    cout << "creating queue of n containers, specified on command line (default 10)" << endl;

    int contCount = 10;
    if (argc == 2)
        contCount = atoi(argv[1]);

    queue<container> cont_q;
    for (int i = 1; i <= contCount; i++)
    {
        cont_q.push(container(i));
    }

    cout << "popping containers from queue" << endl;
    while(!cont_q.empty())
    {
        cont = cont_q.front();
        cont.display();
        cout << endl;
        cont_q.pop();
    }

    return 0;
}