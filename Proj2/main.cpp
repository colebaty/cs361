#include <iostream>
#include <map>
#include <cctype>

#include "menuOptions.h"
#include "module.h"
#include "station.h"
#include "utilities.h"

using namespace std;

int main()
{
    displayHeader();
    char choice;
    bool done = false;
    int modID = 100;

    station station;

    do
    {
        choice = displayMenu();
        switch (tolower(choice))
        {
        case _ADD:
            addMod(station);
            break;
        
        case _EXIT:
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
            break;
        }

    } while (choice != _EXIT);

    #ifdef DEBUG
    cout << "------------------------" << endl;
    for (multimap<int, module>::iterator mit = station.begin(); mit != station.end(); mit++)
    {
        mit->second.display();
    }
    cout << "------------------------" << endl;
    #endif

    return 0;
}