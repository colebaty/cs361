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
#include "shipTrack.h"
#include "shiputils.h"

using namespace std;

int main()
{
    //seed srand
    srand(time(NULL));

    //setup
    cout << "********* setup *********" << endl;
    //ship(s)
    int shipID = 1;
    ship * shipptr = new ship(shipID++);
    cout << "-------------------------" << endl;

    cout << "ships" << endl;
    shipptr->display();

    cout << "-------------------------" << endl;

    //cranes
    int craneID = 1;
    vector<crane> dock;
    for (int i = 0; i < 9; i++)
    {
        dock.push_back(*new crane(craneID++));
    }
    cout << "-------------------------" << endl;
    cout << "cranes" << endl;
    
    for (int i = 0; i < dock.size(); i++)
    {
        dock[i].display();
    }

    cout << "-------------------------" << endl;
    cout << "switch tracks (w/ siding)" << endl;

    //switch tracks
    int swtrackID = 1;
    vector<switchTrack> switchYard;
    for (int i = 0; i < 5; i++)
    {
        switchYard.push_back(*new switchTrack(swtrackID++));
    }

    for (int i = 0; i < switchYard.size(); i++)
    {
        switchYard[i].display();
    }
    
    cout << "-------------------------" << endl;
    
    //shipping tracks
    cout << "shipping tracks" << endl;
    int shipTrackID = 1;
    vector<shipTrack> shipYard;
    for (int i = 0; i < 4; i++)
    {
        shipYard.push_back(*new shipTrack(shipTrackID++));
    }
    
    for (int i = 0; i < shipYard.size(); i++)
    {
        shipYard[i].display();
    }
    
    cout << "-------------------------" << endl;

    //meat

    bool done = false;
    int counter = 0;
    while (!done)
    {
        cout << "-------------------------" << endl;
        cout << "timestep " << counter << endl;
        cout << "-------------------------" << endl;



        //check if done
        counter++;
        if (counter % 10 == 0)
        {
            char ans;
            cout << "advance 10 timesteps? (y/n) ";
            cin >> ans;
            ans == 'n' ? done = true : done = false;
        }
        
    }

    //housekeeping
    
    return 0;
}
