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

    container * cont;
    switchTrack track;

    cout << "filling track to capacity with containers" << endl;
    int contID = 10000;
    while (!track.full())
    {
        cont = new container(contID++);
        track.push(*cont);
    }
    cout << "--------------------" << endl;
    track.display();
    cout << "--------------------" << endl;

    cout << "emptying track" << endl;
    while (!track.empty())
    {
        cout << "getting next container from track" << endl;
        *cont = track.getNext();

        cout << "container " << cont->getID() << " goes to shipping line " 
            << cont->getDest() / 100 << endl;
        cout << "--------------------" << endl;
        
        track.display();
        cout << "--------------------" << endl;
    }

    cout << "creating new track" << endl;

    switchTrack track2;

    cout << "filling track to capacity with containers" << endl;
    contID = 20000;
    while (!track2.full())
    {
        cont = new container(contID++);
        track2.push(*cont);
    }
    track2.display();
    cout << "--------------------" << endl;
    cout << "sorting containers to shipping tracks" << endl;
    
    int shipTrackSize = 3;
    queue<container> shipTracks[shipTrackSize];

    while (!track2.empty())
    {
        
        if ((track2.getNextDest() / 100 ) - 1 < shipTrackSize)
        {
            shipTracks[(track2.getNextDest() / 100) - 1].push(track2.getNext());
        }
        else
        {
            track2.pushToSiding(track2.getNext());
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
    track2.display();
    
    cout << "--------------------" << endl;

    delete cont;

    return 0;
}