/**
 * @file main.cpp
 * @author Cole Baty (tbaty002@odu.edu)
 * @brief shipyard simulation for CS 361 Spring '22 at ODU
 * @version 0.1
 * @date 2022-02-21
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

void preLoadCranes(vector<crane>& dock, int& craneID);
bool switchYardFull(vector<switchTrack>& switchYard);

int main()
{
    //seed srand
    srand(time(NULL));

<<<<<<< HEAD
    cout << "********* setup **********" << endl;
    //ship
    int shipID = 1;
    ship * shipptr = new ship(shipID++);
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
    preLoadCranes(dock, craneID);
    
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
    for (int i = 0; i < 4; i++)
    {
        shipYard.push_back(*new shipTrack(shptrID++, getRand(1, 9)));
    }
    cout << "--------------------------" << endl;
    cout << "shiptrack" << endl;
    for (int i = 0; i < shipYard.size(); i++)
    {
        shipYard[i].display();
    }
    cout << "--------------------------" << endl;

    //main loop
    //begin main loop variable declarations
    /**
     * @brief timestep counter
     * 
     */
    int counter = 0;
    /**
     * @brief whether the program should terminate. conditions generally
     * tested at the end of each iteration of main while loop
     * 
     */
    bool done = false;

    /**
     * @brief iterator for cranes unloading to switch tracks
     * 
     */
    vector<switchTrack>::iterator craneUnloadIt = switchYard.begin();
    vector<switchTrack>::iterator swtrit;

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
    vector<switchTrack>::iterator sw2shpit;
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

        //check that all switch tracks are not full
        if (switchYardFull(switchYard))
        {
            cout << "all switch tracks full; quitting" << endl;
            done = true;
            continue;
        }
        
        //cranes
        craneIt = dock.begin();
        while (craneIt != dock.end() && !switchYardFull(switchYard))
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
                //find next switch track with space available
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
                //skipping last switch track here somehow?
                craneUnloadIt = (next(craneUnloadIt) == switchYard.end())
                                ? switchYard.begin()
                                : next(craneUnloadIt);
            }
            craneIt = next(craneIt);
        }
        
        //switch yard -> ship yard
        sw2shpit = switchYard.begin();
        while (sw2shpit != switchYard.end())
        {
            shpit = shipYard.begin();
            bool match = false;
            while (shpit != shipYard.end() && !match)
            {
                if (sw2shpit->hasNext() &&
                     sw2shpit->getNextDest() / 100 == shpit->getDest())           
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

            if (sw2shpit->hasNext() && !match)
            {
                cout << "switch track " << sw2shpit->getID() << " found no match; "
                     << "pushing container " << sw2shpit->getNextContID()
                     << " to siding" << endl;
                sw2shpit->pushToSiding();
            }
            sw2shpit = next(sw2shpit);
        }

        swtrit = switchYard.begin();
        while (swtrit != switchYard.end() && !swtrit->full() && counter % 5 == 0)
        {
            cout << "refreshing switchyard " <<  swtrit->getID() << endl;
            swtrit->refresh();
            swtrit = next(swtrit);
        }
        
        //shipping trains
        shpit = shipYard.begin();
        while (shpit != shipYard.end())
        {
            if (shpit->ready())
            {
                cout << "shipping train " << shpit->getID() << " ready; departing" << endl;
                shpit->depart();
                shipYard.erase(shpit);
                shipYard.emplace(shpit, *new shipTrack(shptrID++, switchYard[counter % switchYard.size()].getNextDest() / 100));
                cout << "\treplaced with new shipping train " << endl
                     << "\t\tid: " << shpit->getID() << endl
                     << "\t\tdest: " << shpit->getDest() << endl;
            }
            else
            {
                cout << "shipping train " << shpit->getID() << " not ready" << endl;
                shpit->display();
            }
            //update shipping track
            shpit->update();
            //advance iterator
            shpit = next(shpit);
        }

        cout << "--------------------------" << endl;

        if (counter % 10 == 0)
=======
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
    vector<switchTrack>::iterator currSwTr = switchYard.begin();

    while (!done)
    {
        cout << "-------------------------" << endl;
        cout << "timestep " << counter << endl;
        cout << "-------------------------" << endl;

        //load cranes
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
                //find next non-full switch track
                while (currSwTr->full())
                {
                    (currSwTr == switchYard.end()) ? currSwTr = switchYard.begin() 
                                                   : currSwTr = next(currSwTr);
                }

                //unload crane to track
                cout << "crane " << dock[i].getID() << " unloads container "
                     << dock[i].getContID() << " to switch track " << currSwTr->getID() << endl;
                currSwTr->push(dock[i].unload());
                //advance iterator (round robin)
                next(currSwTr) == switchYard.end() ? currSwTr = switchYard.begin()
                                                   : currSwTr = next(currSwTr);
            }
            
        }

        //load switch tracks
        

        //load ship tracks

        //check if done
        counter++;
        if (counter % 2 == 0)
>>>>>>> siding
        {
            char ans;
            cout << "advance 10 timesteps? (y/n) ";
            cin >> ans;
<<<<<<< HEAD
            if (ans == 'n')
            {
                done = true;
            }
            
        }
        if (!shipptr->hasNext())
        {
            cout << "ship empty; departing" << endl;
            shipptr->display();
            delete shipptr;
            shipptr = new ship(shipID++);
            cout << "--------------------------" << endl;
            shipptr->display();
        }
=======
            ans == 'n' ? done = true : done = false;
        }
        else if (!shipptr->hasNext())
        {
            cout << "ship empty; quitting" << endl;
            done = true;
        }
        
>>>>>>> siding
        
    }

    //housekeeping
<<<<<<< HEAD
    delete shipptr;
=======
>>>>>>> siding
    
    return 0;
}

void preLoadCranes(vector<crane>& dock, int& craneID)
{
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

    crit = dock.begin();
    while (crit != dock.end())
    {
        crit->display();
        crit = next(crit);
    }
}

bool switchYardFull(vector<switchTrack>& switchYard)
{
    int swydFullCount = 0;
    vector<switchTrack>::iterator swit = switchYard.begin();
    while (swit != switchYard.end())
    {
        if (swit->full())
        {
            swydFullCount++;
        }
        swit++;
    }


    return swydFullCount == switchYard.size();
}