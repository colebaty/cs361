/**
 * @file phase1Test.cpp
 * @author Cole Baty (tbaty002@odu.edu)
 * @brief main driver for phase 1 deliverable
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <assert.h>
#include <ctime>
#include <cstdlib>
#include <vector>

#include "container.h"
#include "crane.h"
#include "ship.h"
#include "switchTrack.h"
#include "shiputils.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));
    
    //create shipyard
    cout << "****** creating shipyard ******" << endl;
    cout << "creating ship with id 1" << endl;
    ship * shipptr = new ship(1);
    assert(shipptr->getID() == 1);

    cout << "creating vector of 9 cranes" << endl;
    vector<crane> cranes;
    crane * craneptr;
    for (int i = 0; i < 9; i++)
    {
        craneptr = new crane(i);
        cranes.push_back(*craneptr);
    }
    assert(cranes.size() == 9);

    cout << "creating vector of 5 switch tracks" << endl;
    vector<switchTrack> switchTracks;
    switchTrack * swtrptr;
    for (int i = 0; i < 5; i++)
    {
        swtrptr = new switchTrack(i);
        switchTracks.push_back(*swtrptr);
    }
    assert(switchTracks.size() == 5);

    //fill tracks to nearly full
    container * contptr;
    for (int i = 0; i < switchTracks.size(); i++)
    {
        for (int j = 0; j < getRand(35,38); j++)
        {
            contptr = new container((j+1) * 10000);
            switchTracks[i].push(*contptr);
        }
        assert(35 <= switchTracks[i].size() && switchTracks[i].size() <= 38);
    }
    cout << "********************************" << endl;

    //begin timestep
    bool done = false;
    int counter = 0;
    
    //pointer to switch track to start with on next timestep
    switchTrack * nextTrack = &switchTracks[switchTracks.size() - 1];
    int index = 0;
    int contID = shipptr->getID() * 10000;
    while (!done)
    {
        cout << "timestep " << counter << endl;
        cout << "--------------------" << endl;
        //cranes
        for (int i = 0; i < cranes.size(); i++)
        {
            //all unloaded cranes collect one container from ship
            if (cranes[i].empty())
            {
                cout << "crane " << cranes[i].getID() << " empty; loading container from ship" << endl;
                contptr = new container(contID++);
                contptr->display();
                cranes[i].load(*contptr);
                assert(contptr->getID() == cranes[i].getContID());
                assert(!cranes[i].empty());
            }
            else
            {
                cout << "crane " << cranes[i].getID() << " loaded with container "
                     << cranes[i].getContID() << endl;

                while (nextTrack->full())
                {
                    cout << "track " << nextTrack->getID() << " full; skipping" << endl;
                    nextTrack = &switchTracks[++index % switchTracks.size()];
                }
                
                *contptr = cranes[i].unload();
                nextTrack->push(*contptr);
                cout << "crane " << cranes[i].getID() << " unloaded to track "
                    << nextTrack->getID() << endl;
                nextTrack = &switchTracks[index % switchTracks.size()];
                
                index++;
            }
        }
        cout << "--------------------" << endl;

        //timestep housekeeping
        counter++;
        //prompt to continue every 10 timesteps
        char ans;
        if (counter % 5 == 0)
        {
            cout << "advance 5 more timesteps? (y/n) ";
            cin >> ans;
            if (ans == 'n') done = true;
        }
    }
    
    return 0;
}
