#include <iostream>
#include <cctype>
#include "menuOptions.h"

using namespace std;

void displayHeader()
{
    cout << "***************************************" << endl;
    cout << "********** SPACE STATION **************" << endl;
    cout << "***************************************" << endl;

}

char displayMenu()
{
    cout << "MAIN MENU" << endl
         << "\tA) ADD MODULE" << endl
         << "\tB) MOVE MODULE" << endl
         << "\tC) SAVE CURRENT CONFIG" << endl
         << "\tD) DRAW SPACECRAFT (GNUPLOT)" << endl
         << "\tE) LOAD CONFIG" << endl
         << "\tF) VERIFY CURR. CONFIG CONN." << endl
         << "\tG) EXIT" << endl
         << endl
         << "CHOICE: ";
    char choice;
    cin >> choice;

    return choice;
}

types displayAddModMenu()
{
    cout << "ADD WHICH MODULE?" << endl
         << "\t1. HALLWAY" << endl
         << "\t2. HOUSING" << endl
         << "\t3. POWER" << endl
         << "\t4. LAB" << endl
         << "\t5. EXERCISE" << endl
         << "\t6. STORAGE" << endl
         << "\t7. RETURN TO MAIN" << endl
         << endl
         << "CHOICE: ";

    int choice;
    cin >> choice;

    return (types) choice;

}