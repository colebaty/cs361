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

    cout << "********* setup **********" << endl;
    //ship
    ship * shipptr = new ship(1);
    cout << "--------------------------" << endl;
    cout << "ship" << endl;
    shipptr->display();
    cout << "--------------------------" << endl;

    //cranes
    vector<crane> dock;
    int craneID = 1;
    for (int i = 0; i < 9; i++)
    {
        dock.push_back(*new crane(craneID++));
    }
    cout << "--------------------------" << endl;
    cout << "cranes" << endl;
    for (int i = 0; i < dock.size(); i++)
    {
        dock[i].display();
    }
    
    cout << "--------------------------" << endl;

    //switchyard
    vector<switchTrack> switchYard;
    int swtrID = 1;
    for (int i = 0; i < 5; i++)
    {
        switchYard.push_back(*new switchTrack(swtrID++));
    }
    cout << "--------------------------" << endl;
    cout << "switchyard" << endl;
    for (int i = 0; i < switchYard.size(); i++)
    {
        switchYard[i].display();
    }
    cout << "--------------------------" << endl;

    //shipping yard
    vector<shipTrack> shipYard;
    int shptrID = 1;
    for (int i = 0; i < 5; i++)
    {
        shipYard.push_back(*new shipTrack(shptrID++));
    }
    cout << "--------------------------" << endl;
    cout << "shiptrack" << endl;
    for (int i = 0; i < shipYard.size(); i++)
    {
        shipYard[i].display();
    }
    cout << "--------------------------" << endl;

    //main loop

    cout << "--------------------------" << endl;
    cout << "loading container from ship into crane 0" << endl;
    dock[0].load(shipptr->getNext());
    shipptr->display();
    dock[0].display();
    cout << "--------------------------" << endl;
    cout << "unloading container from crane 0 into switch track 0" << endl;
    switchYard[0].push(dock[0].unload());
    dock[0].display();
    switchYard[0].display();
    cout << "--------------------------" << endl;
    cout << "pushing container to ship track 0" << endl;
    shipYard[0].push(switchYard[0].getNext());
    switchYard[0].display();
    shipYard[0].display();
    cout << "--------------------------" << endl;
    shipptr->display();
    dock[0].display();
    switchYard[0].display();
    shipYard[0].display();
    cout << "--------------------------" << endl;

    //begin main loop variable declarations
    /**
     * @brief timestep counter
     * 
     */
    int counter = 0;
    /**
     * @brief whether the program should terminate. conditions should be
     * tested at the end of each iteration of main while loop
     * 
     */
    bool done = false;

    /**
     * @brief iterator for cranes unloading to switch tracks
     * 
     */
    vector<switchTrack>::iterator craneUnloadIt = switchYard.begin();
    
    /**
     * @brief iterator for passing containers from switching yard 
     * to shipping tracks
     * 
     */
    vector<switchTrack>::iterator sw2shpit = switchYard.begin();
    /**
     * @brief iterator for passing containers from switching yard 
     * to shipping tracks
     * 
     */
    vector<shipTrack>::iterator shpit;

    while (!done)
    {
        //cranes
        for (int i = 0; i < dock.size(); i++)
        {
            if (dock[i].empty())
            {
                dock[i].load(shipptr->getNext());
                cout << "crane " << dock[i].getID() << " loaded container "
                     << dock[i].getContID() << endl;
            }
            else
            {
                while (craneUnloadIt->full())
                {
                    if (next(craneUnloadIt) == switchYard.end())
                        craneUnloadIt = switchYard.begin();
                    else
                        craneUnloadIt = next(craneUnloadIt);
                }
                cout << "crane " << dock[i].getID() << " unloaded container "
                     << dock[i].getContID() << " to switch track " 
                     << craneUnloadIt->getID() << endl;
                     
                craneUnloadIt->push(dock[i].unload());

                next(craneUnloadIt) == switchYard.end() 
                    ? craneUnloadIt = switchYard.begin()
                    : craneUnloadIt = next(craneUnloadIt);
            }
        }
        cout << "--------------------------" << endl;

        while (sw2shpit != switchYard.end())
        {
            shpit = shipYard.begin();
            while (shpit != shipYard.end())
            {
                if (sw2shpit->getNextDest() / 100 == shpit->getDest())           
                {
                    shpit->push(sw2shpit->getNext());
                }
                shpit = next(shpit);
            }
            sw2shpit = next(sw2shpit);
        }

        counter ++;
        if (counter % 10 == 0)
        {
            char ans;
            cout << "advance 10 timesteps? (y/n) ";
            cin >> ans;
            if (ans == 'n')
            {
                done = true;
            }
            
        }
        if (!shipptr->hasNext())
        {
            cout << "ship empty; quitting" << endl;
            shipptr->display();
            done = true;
        }
        
    }

    //housekeeping
    
    return 0;
}
