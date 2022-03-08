#include <iostream>
#include "menuOptions.h"

using namespace std;

void displayHeader()
{
    cout << "***************************************" << endl;
    cout << "********** SPACE STATION **************" << endl;
    cout << "***************************************" << endl;

}

void displayMenu()
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
}

void displayAddModMenu()
{
    cout << "ADD WHICH MODULE?" << endl
         << "\t1. HOUSING" << endl
         << "\t2. POWER" << endl
         << "\t3. LAB" << endl
         << "\t4. EXERCISE" << endl
         << "\t5. STORAGE" << endl
         << "\t6. RETURN TO MAIN" << endl
         << endl
         << "CHOICE: ";
}