#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>

#include "container.h"
#include "switchTrack.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    cout << "creating new track" << endl;
    switchTrack swtr(1);
    swtr.display();
    cout << "--------------------" << endl;

    cout << "filling track to capacity with containers" << endl;
    int contID = 20000;
    container * cont;
    while (!swtr.full())
    {
        cont = new container(contID++);
        swtr.push(*cont);
    }
    swtr.display();
    cout << "--------------------" << endl;
    cout << "sorting containers to shipping tracks" << endl;
    
    int shipTrackSize = 5;
    queue<container> shipTracks[shipTrackSize];

    while (!swtr.empty())
    {
        if ((swtr.getNextDest() / 100 ) - 1 < shipTrackSize)
        {
            cout << "pushing onto shipping train" << endl;
            shipTracks[(swtr.getNextDest() / 100) - 1].push(swtr.getNext());
        }
        else
        {
            cout << "pushing onto siding" << endl;
            swtr.pushToSiding();
        }
    }

    for (int i = 0; i < shipTrackSize; i++)
    {
        cout << "shipping track " << i << ": " << shipTracks[i].size() << endl;
    }
    int sum = 0;
    for (int i = 0; i < shipTrackSize; i++)
    {
        sum += shipTracks[i].size();
    }

    cout << sum << " containers loaded onto 9 tracks " << endl;
    swtr.display();
    
    cout << "--------------------" << endl;
    cout << "********** siding testing **********" << endl;
    switchTrack swtr2(2, 10);

    cout << "filling track" << endl;
    while (!swtr2.full())
    {
        swtr2.push(*new container(contID++));
        swtr2.pushToSiding();
    }

    swtr2.display();

    cout << "--------------------" << endl;

    cout << "emptying track" << endl;

    queue<container> q;

    while (swtr2.hasNext())
    {
        cout << "from main track" << endl;
        *cont = swtr2.getNext();
        cont->display();
        q.push(*cont);

        cout << endl;

        cout << "from siding" << endl;
        *cont = swtr2.getNextFromSiding();
        cont->display();
        q.push(*cont);

        cout << endl;
    }

    cout << "--------------------" << endl;

    swtr2.display();

    cout << "--------------------" << endl;
    cout << "testing switchTrack::refresh()" << endl;

    switchTrack swtr3(3, 10);
    cout << "filling track" << endl;
    while (!swtr3.full())
    {
        swtr3.push(*new container(contID++));
    }

    swtr3.display();

    cout << "pushing half to siding" << endl;
    for (int i = 0; i < 5; i++)
    {
        swtr3.pushToSiding();
    }
    swtr3.display();

    cout << "emptying main track" << endl;
    while (!swtr3.empty())
    {
        swtr3.getNext();
    }

    swtr3.display();

    cout << "refreshing track" << endl;
    swtr3.refresh();
    swtr3.display();
    
    cout << "--------------------" << endl;


    return 0;
}