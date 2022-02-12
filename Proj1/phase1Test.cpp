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

using namespace std;

int main()
{
    //create shipyard
    ship * shipptr = new ship(0);

    vector<crane> cranes;
    crane * craneptr;
    for (int i = 0; i < 9; i++)
    {
        craneptr = new crane(i);
        cranes.push_back(*craneptr);
    }

    vector<switchTrack> switchTracks;
    switchTrack * swtrptr;
    for (int i = 0; i < 5; i++)
    {
        swtrptr = new switchTrack(i);
        switchTracks.push_back(*swtrptr);
    }

    //begin timestep
    bool done = false;
    int counter = 0;
    
    //pointer to switch track to start with on next timestep
    switchTrack * next = &switchTracks[0];
    while (!done)
    {
        cout << "--------------------" << endl;
        //cranes
        for (int i = 0; i < cranes.size(); i++)
        {
            //all unloaded cranes collect one container from ship
            if (cranes[i].empty())
            {
                //get next container from ship
                cout << "crane " << cranes[i].getID() << " loaded" << endl;
            }
            else //all loaded cranes deposit container to next available track
            {
                int start = next->getID();
                for (int t = 0; t < switchTracks.size(); t++)
                {
                    switchTracks[start % switchTracks.size()].push(craneptr[i].unload());
                    cout << "crane " << cranes[i].getID() << " added container to track " 
                         << switchTracks[start % switchTracks.size()].getID() << endl;
                    start++;
                }
                next = &switchTracks[start];
            }
        }
        cout << "--------------------" << endl;

        //timestep housekeeping
        counter++;
        //prompt to continue every 10 timesteps
        char ans;
        if (counter % 10 == 0)
        {
            cout << "advance 10 more timesteps? (y/n) ";
            cin >> ans;
            if (ans == 'n') done = true;
        }
    }
    
    return 0;
}
