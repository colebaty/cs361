#include <iostream>

#include "menuOptions.h"

using namespace std;

int main()
{
    displayHeader();

    bool done = false;
    char choice;
    do
    {
        displayMenu();
        cin >> choice;
        switch (choice)
        {
        case 'a':
        case 'A':
            displayAddModMenu();
            cin >> choice;
            done = true;
            break;
        
        case 'g':
        case 'G':
        default:
            break;
        }
    } while (!done);

    return 0;
}