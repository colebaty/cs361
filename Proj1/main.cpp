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

    cout << "preloading cranes 1, 4, 7, 8" << endl;
    vector<crane>::iterator crit = dock.begin();
    while (crit != dock.end())
    {
        switch (crit->getID())
        {
        case 1:
            crit->load(*new container(craneID++));
            break;
        case 4:
            crit->load(*new container(craneID++));
            break;
        
        case 7:
            crit->load(*new container(craneID++));
            break;
        
        case 8:
            crit->load(*new container(craneID++));
            break;
        
        
        default:
            break;
        }

        crit = next(crit);
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

    // cout << "--------------------------" << endl;
    // cout << "loading container from ship into crane 0" << endl;
    // dock[0].load(shipptr->getNext());
    // shipptr->display();
    // dock[0].display();
    // cout << "--------------------------" << endl;
    // cout << "unloading container from crane 0 into switch track 0" << endl;
    // switchYard[0].push(dock[0].unload());
    // dock[0].display();
    // switchYard[0].display();
    // cout << "--------------------------" << endl;
    // cout << "pushing container to ship track 0" << endl;
    // shipYard[0].push(switchYard[0].getNext());
    // switchYard[0].display();
    // shipYard[0].display();
    // cout << "--------------------------" << endl;
    // shipptr->display();
    // dock[0].display();
    // switchYard[0].display();
    // shipYard[0].display();
    // cout << "--------------------------" << endl;

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
     * @brief iterator for crane selection
     * 
     */
    vector<crane>::iterator craneIt;
    
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
        cout << "--------------------------" << endl;
        cout <<" timestep " << counter++ << endl;;
        cout << "--------------------------" << endl;
        //cranes
        craneIt = dock.begin();
        while (craneIt != dock.end())
        {
            if (craneIt->empty())
            {
                craneIt->load(shipptr->getNext());
                cout << "crane " << craneIt->getID() << " loaded container "
                     << craneIt->getContID() 
                     << " from ship " << shipptr->getID() << endl;
            }
            else
            {
                //find next empty switch track
                while (craneUnloadIt->full())
                {
                    next(craneUnloadIt) == switchYard.end()
                        ? craneUnloadIt = switchYard.begin()
                        : craneUnloadIt = next(craneUnloadIt);
                }

                cout << "crane " << craneIt->getID() << " unloaded container "
                     << craneIt->getContID() << " to switch track " 
                     << craneUnloadIt->getID() << endl;
                craneUnloadIt->push(craneIt->unload());

                //advance crane unload iterator, with wraparound
                next(craneUnloadIt) == switchYard.end()
                    ? craneUnloadIt = switchYard.begin()
                    : craneUnloadIt = next(craneUnloadIt);

            }
            craneIt = next(craneIt);
        }
        
        //switch yard -> ship yard
        while (sw2shpit != switchYard.end())
        {
            shpit = shipYard.begin();
            bool match = false;
            while (shpit != shipYard.end() && !match)
            {
                if (sw2shpit->getNextDest() / 100 == shpit->getDest())           
                {
                    cout << "switch track " << sw2shpit->getID() 
                         << " gave container " << sw2shpit->getNextContID()
                         << " with dest " << sw2shpit->getNextDest()
                         << " to ship track " << shpit->getID() << endl;
                    shpit->push(sw2shpit->getNext());
                    match = true;
                }
                shpit = next(shpit);
            }

            if (!sw2shpit->empty() && !match)
            {
                cout << "switch track " << sw2shpit->getID() << " found no match; "
                     << " pushing container " << sw2shpit->getNextContID()
                     << " to siding" << endl;
                sw2shpit->pushToSiding();
            }
            sw2shpit = next(sw2shpit);
        }

        cout << "--------------------------" << endl;

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
