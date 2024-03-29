#include <iostream>
#include <random>
#include <ctime>
#include <cassert>

#include "node.h"

using namespace std;

int main()
{
    node n;
    n.display();

    cout << "----------------------" << endl;

    node * nptr = new node(1);

    for (int i = _A; i <= _E; i++)
    {
        nptr->push(i);
    }

    nptr->display();
    cout << "pushing one more, then displaying" << endl;

    nptr->push(_Z);
    nptr->display();

    cout << "----------------------" << endl;
    cout << "testing search" << endl;
    cout << "testing for value known to be in queue (Z)...";
    assert(nptr->search('Z'));
    cout << "pass" << endl;
    cout << "----------------------" << endl;
    cout << "testing for value known NOT to be in queue (X)...";
    assert(!nptr->search('X'));
    cout << "pass" << endl;

    delete nptr;

    cout << "----------------------" << endl;
    cout << "randomly adding letters" << endl;
    default_random_engine gen(time(NULL));
    uniform_int_distribution<int> ldist(_A, _Z);//letter distribution
    /**
     * during testing, discovered that the first value is always the same for
     * a default random engine seeded the way it is above. this call is just to
     * discard that first value
     */
    ldist(gen);
    nptr = new node(2);
    for (int i = _A; i < _Z; i++)
    {
        nptr->push(ldist(gen));
    }
    
    nptr->display();

    return 0;
}
