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

    station station(1);

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

    return 0;
}