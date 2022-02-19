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

    vector<switchTrack> switchYard;

    cout << "creating, filling two switching tracks" << endl;
    for (int i = 0; i <= 1; i++)
    {
        switchYard.push_back(*new switchTrack(i+1));
    }

    int contID = 0;
    for (int i = 0; i < switchYard.size(); i++)
    {
        contID = switchYard[i].getID() * 10000;
        while(!switchYard[i].full())
        {
            switchYard[i].push(*new container(++contID));
        }

        cout << "switchTrack: " << switchYard[i].getID() << endl;
        switchYard[i].display();
    }

    cout << "-------------------------" << endl;

    

    return 0;
}