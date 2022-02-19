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

    // vector<switchTrack> switchYard;

    // cout << "creating, filling " << switchYardCap << " switching tracks" << endl;
    // for (int i = 0; i < switchYardCap; i++)
    // {
    //     switchYard.push_back(*new switchTrack(i+1));
    // }

    // for (int i = 0; i < switchYard.size(); i++)
    // {
    //     contID = switchYard[i].getID() * 10000;
    //     while(switchYard[i].size() < getRand(37, 40))
    //     {
    //         switchYard[i].push(*new container(++contID));
    //     }

    //     cout << "switchTrack: " << switchYard[i].getID() << endl;
    //     switchYard[i].display();
    // }

    // cout << "-------------------------" << endl;

    // cout << "creating new shipping track with random dest code, ttl > cap" << endl;
    // shipTrack s(1, 100, 30);
    // s.display();
    // cout << "-------------------------" << endl;

    // cout << "sorting containers" << endl;

    // while(!s.ready())
    // {
    //     cout << "-------------------------" << endl;
    //     cout << "timestep " << counter++ << endl;
    //     cout << "-------------------------" << endl;
    //     for (int i = 0; i < switchYard.size(); i++)
    //     {
    //         if (!switchYard[i].empty())
    //         {
    //             if (switchYard[i].getNextDest() / 100 == s.getDest())
    //             {
    //                 cout << "switch track " << switchYard[i].getID() << " gives to "
    //                     << s.getID() << endl;
    //                 s.push(switchYard[i].getNext());
    //             }
    //             else
    //             {
    //                 cout << "track " << switchYard[i].getID() << " no match: pushing to siding" 
    //                     << endl; 
    //                 switchYard[i].pushToSiding();
    //             }
    //         }
    //         else
    //         {
    //             cout << "track " << switchYard[i].getID() << " empty" << endl;
    //         }

    //         #ifdef DEBUG
    //             cout << "track: " << switchYard[i].getID() << endl;
    //             switchYard[i].display();
    //             cout << endl;
    //         #endif
    //     }
    //     s.update();
    //     cout << "shipping train leaves in " << s.getTTL() << " timesteps" << endl;
    // }

    // cout << "-------------------------" << endl;

    // cout << "shipping train ready" << endl;
    // s.display();

    // cout << "-------------------------" << endl;

    // for (int i = 0; i < switchYard.size(); i++)
    // {
    //     cout << "switchTrack: " << switchYard[i].getID() << endl;
    //     switchYard[i].display();
    // }

    // cout << "-------------------------" << endl;


    //******* switch yard 2 ***********

    vector<switchTrack> switchYard2;

    cout << "creating, filling " << switchYardCap << " switching tracks" << endl;
    for (int i = 0; i < switchYardCap; i++)
    {
        switchYard2.push_back(*new switchTrack(i+1));
    }

    for (int i = 0; i < switchYard2.size(); i++)
    {
        contID = switchYard2[i].getID() * 10000;
        while(switchYard2[i].size() < getRand(37, 40))
        {
            switchYard2[i].push(*new container(++contID));
        }

        cout << "switchTrack: " << switchYard2[i].getID() << endl;
        switchYard2[i].display();
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
        for (int i = 0; i < switchYard2.size(); i++)
        {
            while (!switchYard2[i].full())
            {
                switchYard2[i].push(*new container(contID));
            }
            
        }
        
        
        for (int i = 0; i < switchYard2.size(); i++)
        {
            if (switchYard2[i].getNextDest() / 100 == s2.getDest())
            {
                cout << "switch track " << switchYard2[i].getID() << " gives to "
                     << s2.getID() << endl;
                s2.push(switchYard2[i].getNext());
            }
            else
            {
                cout << "no match: pushing to siding" << endl; 
                switchYard2[i].pushToSiding();
            }

            #ifdef DEBUG
                cout << "track: " << switchYard2[i].getID() << endl;
                switchYard2[i].display();
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

    for (int i = 0; i < switchYard2.size(); i++)
    {
        cout << "switchTrack: " << switchYard2[i].getID() << endl;
        switchYard2[i].display();
    }

    cout << "-------------------------" << endl;

    return 0;
}