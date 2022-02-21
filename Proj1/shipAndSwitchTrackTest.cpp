#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>

#include "container.h"
#include "shipTrack.h"
#include "switchTrack.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    int switchYardCap = 5;
    int contID = 0;
    int counter = 1;

    //******* switch yard 2 ***********

    vector<switchTrack> switchYard;

    cout << "creating, filling " << switchYardCap << " switching tracks" << endl;
    for (int i = 0; i < switchYardCap; i++)
    {
        switchYard.push_back(*new switchTrack(i+1));
    }

    for (int i = 0; i < switchYard.size(); i++)
    {
        contID = switchYard[i].getID() * 10000;
        while(switchYard[i].size() < getRand(37, 40))
        {
            switchYard[i].push(*new container(++contID));
        }

        cout << "switchTrack: " << switchYard[i].getID() << endl;
        switchYard[i].display();
    }

    cout << "-------------------------" << endl;
    cout << "creating new shipping track with random dest code, ttl < cap" << endl;
    shipTrack s2(2, 10, 100);
    s2.display();
    cout << "-------------------------" << endl;

    cout << "sorting containers" << endl;

    counter = 1;
    while(!s2.ready())
    {
        cout << "-------------------------" << endl;
        cout << "timestep " << counter++ << endl;
        cout << "-------------------------" << endl;
        cout << "refilling switchTracks" << endl;
        for (int i = 0; i < switchYard.size(); i++)
        {
            while (!switchYard[i].full())
            {
                switchYard[i].push(*new container(contID));
            }
            
        }
        
        
        for (int i = 0; i < switchYard.size(); i++)
        {
            if (switchYard[i].getNextDest() / 100 == s2.getDest())
            {
                cout << "switch track " << switchYard[i].getID() << " gives to "
                     << s2.getID() << endl;
                s2.push(switchYard[i].getNext());
            }
            else
            {
                cout << "no match: pushing to siding" << endl; 
                switchYard[i].pushToSiding();
            }

            #ifdef DEBUG
                cout << "track: " << switchYard[i].getID() << endl;
                switchYard[i].display();
                cout << endl;
            #endif
        }
        s2.update();
        cout << "shipping train leaves in " << s2.getTTL() << " timesteps" << endl;
    }

    cout << "-------------------------" << endl;

    cout << "shipping train ready" << endl;
    s2.display();

    cout << "-------------------------" << endl;

    for (int i = 0; i < switchYard.size(); i++)
    {
        cout << "switchTrack: " << switchYard[i].getID() << endl;
        switchYard[i].display();
    }

    cout << "-------------------------" << endl;

    return 0;
}