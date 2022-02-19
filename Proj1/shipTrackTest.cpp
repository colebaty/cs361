#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>

#include "container.h"
#include "shipTrack.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    cout << "creating new shipTrack, capacity 10, ttl 10" << endl;

    shipTrack * shipptr = new shipTrack(1, 10, 10);
    shipptr->display();

    cout << "-----------------------" << endl;

    int contID = 10000;
    while (!shipptr->ready())
    {
        shipptr->push(*new container(contID++));
        shipptr->update();
    }

    shipptr->display();


    cout << "-----------------------" << endl;
    cout << "pushing to full track; expecting error" << endl;
    shipptr->push(*new container(contID++));

    cout << "-----------------------" << endl;

    cout << "creating new shipTrack, capacity 30, ttl 10" << endl;
    shipptr = new shipTrack(2, 10, 30);

    shipptr->display();

    cout << "-----------------------" << endl;

    contID = 20000;
    while (!shipptr->ready())
    {
        shipptr->push(*new container(contID++));
        shipptr->update();
    }

    shipptr->display();

    cout << "-----------------------" << endl;

    cout << "creating new shipTrack, capacity 10, ttl 30" << endl;
    shipptr = new shipTrack(3, 30, 10);

    shipptr->display();

    cout << "-----------------------" << endl;

    contID = 30000;
    while (!shipptr->ready())
    {
        shipptr->push(*new container(contID++));
        shipptr->update();
    }

    shipptr->display();

    cout << "-----------------------" << endl;

    return 0;
}