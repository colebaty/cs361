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

    int counter = 0;
    bool done = false;
    vector<switchTrack>::iterator swtrit = switchYard.begin();
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
                while (swtrit->full())
                {
                    if (next(swtrit) == switchYard.end())
                        swtrit = switchYard.begin();
                    else
                        swtrit = next(swtrit);
                }
                cout << "crane " << dock[i].getID() << " unloaded container "
                     << dock[i].getContID() << " to switch track " << swtrit->getID() << endl;
                swtrit->push(dock[i].unload());
                swtrit == switchYard.end() ? swtrit = switchYard.begin()
                                           : swtrit = next(swtrit);
            }
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
            done = true;
        }
        
    }

    //housekeeping
    
    return 0;
}
