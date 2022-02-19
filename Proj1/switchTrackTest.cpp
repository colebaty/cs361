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


    return 0;
}